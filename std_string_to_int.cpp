#include <iostream>
#include <cstdlib>

int main()
{
    // const char *begin = "10 200000000000000000000000000000 30 40";
    const char *begin = "10 20000000000 30 40";
    // const char *begin = "10 200 30 40";
    std::cout << std::string(begin) << std::endl;
    char *end;
    for (unsigned long i = std::strtoul(begin, &end, 10);
         begin != end;
         i = std::strtoul(begin, &end, 10))
    {
        begin = end;
        if (errno == ERANGE)
        {
            std::cout << "range error\n";
            errno = 0;
        }
        else
            std::cout << i << '\n';
    }
}