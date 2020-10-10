#include "foo.h"
#include <iostream>
int main()
{
    foo f;
    f.ShowNormal();
    foo::ShowStatic();
    std::cout << "Foo Static = " << foo::staticVal << std::endl;
}