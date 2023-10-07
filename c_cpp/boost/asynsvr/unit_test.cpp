#include <gtest/gtest.h>
#include <iostream>

#include <cstdlib>
#include <cstring>

#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "processor.h"

#define PORT 5001       /* the port client will be connecting to */
#define MAXDATASIZE 100 /* max number of bytes we can get at once */

class MyClassTest : public testing::Test
{
public:
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    void SetUp()
    {
        std::cout << "Start" << std::endl;
        char buf[MAXDATASIZE];
        struct hostent *he;
        struct sockaddr_in their_addr; /* connector's address information */

        if ((he = gethostbyname("127.0.0.1")) == NULL)
        { /* get the host info */
            herror("gethostbyname");
            exit(1);
        }

        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
            perror("socket");
            exit(1);
        }

        their_addr.sin_family = AF_INET;   /* host byte order */
        their_addr.sin_port = htons(PORT); /* short, network byte order */
        their_addr.sin_addr = *((struct in_addr *)he->h_addr);
        bzero(&(their_addr.sin_zero), 8); /* zero the rest of the struct */

        if (connect(sockfd, (struct sockaddr *)&their_addr,
                    sizeof(struct sockaddr)) == -1)
        {
            perror("connect");
            exit(1);
        }
    }

    void TearDown()
    {
        close(sockfd);
    }
};

TEST_F(MyClassTest, ReqViaSocket)
{
    {
        char *msg = "5 * 3\n";
        if (send(sockfd, msg, strlen(msg), 0) == -1)
        {
            perror("send");
            exit(1);
        }
        printf("After the send function \n");

        if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("Received in pid=%d, text=: %s \n", getpid(), buf);
        std::string res(buf, buf + strlen(buf));
        ASSERT_EQ(res, "15");
    }
    {
        char *msg = "(3+ 2*4) * 7\n";
        if (send(sockfd, msg, strlen(msg), 0) == -1)
        {
            perror("send");
            exit(1);
        }
        printf("After the send function \n");

        if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("Received in pid=%d, text=: %s \n", getpid(), buf);
        std::string res(buf, buf + strlen(buf));
        ASSERT_EQ(res, "77");
    }

    {
        char *msg = "(3+ 2*4) * 7*(5+5)\n";
        if (send(sockfd, msg, strlen(msg), 0) == -1)
        {
            perror("send");
            exit(1);
        }
        printf("After the send function \n");

        if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
        {
            perror("recv");
            exit(1);
        }
        printf("Received in pid=%d, text=: %s \n", getpid(), buf);
        std::string res(buf, buf + strlen(buf));
        ASSERT_EQ(res, "770");
    }
}

TEST_F(MyClassTest, Evaluating)
{
    VuNguyen::Evaluator ev;
    {
        const VuNguyen::expression *const ex = ev.parse("(4+3)*2/5");
        assert("Sanity check" && ex);
        ASSERT_EQ((*ex)(), 2);
    }
    {
        const VuNguyen::expression *const ex = ev.parse("((12+9)/2)*5");
        assert("Sanity check" && ex);
        ASSERT_EQ((*ex)(), 50);
    }
    {
        const VuNguyen::expression *const ex = ev.parse("(3/2+2*4)*7+(4-6/3)+1-10");
        assert("Sanity check" && ex);
        ASSERT_EQ((*ex)(), 56);
    }
    {
        const VuNguyen::expression *const ex = ev.parse("(4+3)*2/5+((12+9)/2)*5+(3/2+2*4)*7+(4-6/3)+1-10");
        assert("Sanity check" && ex);
        ASSERT_EQ((*ex)(), 2 + 50 + 56);
    }
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
