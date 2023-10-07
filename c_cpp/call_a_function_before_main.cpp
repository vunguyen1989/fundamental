/*
    [x] global variable
    [x] static data  member
    [] declaration of static data member
        From the standard (N3690): 9.4.2. §2
        The declaration of a static data member in its class definition is not a definition and may be of 
        an incomplete type other than cv-qualified void. 
*/
#include <iostream>

int foo()
{
    std::cout << "in foo() \n";
    return 10;
}

class Base
{
public:
    static int sInt;
    Base()
    {
        foo();
    }
};

int Base::sInt = foo(); //have to add "int" at the beginning (kind of redeclaration)

Base b;

int main()
{
    std::cout << "in  main() \n";
}