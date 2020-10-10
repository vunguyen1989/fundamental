#include "foo.h"
foo::foo(/* args */)
{
}

foo::~foo()
{
}
void foo::ShowStatic()
{
    std::cout << staticVal << std::endl;
}
int foo::staticVal = 5;