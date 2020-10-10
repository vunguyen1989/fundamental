/*
    [x] implicit call of constructor
    [x] normal call of constructor
    [x] the purpose of explicit keyword
*/

#include <iostream>
using namespace std;

class Base
{
    int val;

public:
    explicit Base(int x)
    {
        val = x;
        std::cout << "Constructor with val = " << val << std::endl;
    }
    int Value() { return val; }
};

void foo(Base b)
{
    std::cout << "foo with Base.val = " << b.Value() << std::endl;
}

int main()
{
    Base b(5);
    Base b1 = 10;

    foo(b);
    foo(20);
}
