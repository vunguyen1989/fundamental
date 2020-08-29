#include <iostream>

class Parent {
public:
    Parent()
    {
        std::cout << "Parent" << std::endl;
    }

    virtual ~Parent()
    {
        std::cout << "~Parent" << std::endl;
    }

    virtual void crash() = 0;
};

class Child : public Parent {
public:
    Child()
    {
        std::cout << "Child" << std::endl;
    }

    virtual ~Child()
    {
        std::cout << "~Child" << std::endl;
    }

    void crash() {
        return;
    }
};

int main()
{
    Child *p = new Child();
    p->~Child();
    p->crash();
    return 0;
}
