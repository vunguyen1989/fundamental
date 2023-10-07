#include <iostream>

class Parent
{
public:
    Parent()
    {
        init();
    }

    virtual ~Parent()
    {
    }

    virtual void crash() = 0;
    void init()
    {
        // Call Pure Virtaul
        crash();
    }
};

class Child : public Parent
{
public:
    Child()
    {
    }

    void crash()
    {
        return;
    }

};

int main()
{
    Child c;
    return 0;
}
