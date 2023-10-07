Dear Interviewers,

My solution is kind of simple and far from production i think, just make it work sounding like a prototype version.
I have short time and a bit busy so far, hope this solution is fine for your first round's demand.  
There should be some bugs, i left them there. If having chance for next round then i will be very happy to discuss with you guys about the bugs.

1) Document
The solution use boost::asio for network i/o. It's enough for c10k issue.
https://stackoverflow.com/questions/29888435/boost-asio-and-array-of-sockets

I use Binary Expression Tree for evaluating the expression.
https://stackoverflow.com/questions/17806760/binary-expression-tree-c

And gtest is for unit test.

2) Build
    #for server
        g++ -O2 {checker,processor,session,server,server_main}.cpp -o server -lboost_system -lboost_thread -lpthread -std=c++17
    #for client
        g++ cli.cpp -o cli -lboost_system -lboost_thread -lpthread -std=c++17
    #for unit test
        g++ {processor,unit_test}.cpp -o unit_test -lgtest -pthread -lboost_system

3) Run
    #for server
        ./server
    #for client - a small performance test       
        ./cli 
    #for client        
        ./unit_test 
            # ReqViaSocket  : checking the functionality of the application via tcp client
            # Evaluating    : test the evaluating function
    # Using telnet
        telnet 127.0.0.1 5001
    
Hope to see you at the next round.
Thank You!