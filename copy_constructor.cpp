/*
[x] why copy constructor always take parameter as a reference
[] when is copy construtor called?
    1. When an object of the class is returned by value.
    2. When an object of the class is passed (to a function) by value as an argument.
    3. When an object is constructed based on another object of the same class.
    4. When the compiler generates a temporary object.
[] When is user-defined copy constructor needed?
    If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each 
    class which does a member-wise copy between objects. The compiler created copy constructor works fine in general. 
    We need to define our own copy constructor only if an object has pointers or any runtime allocation of the resource like file handle, 
    a network connection..etc.
        Default constructor does only shallow copy.
        Deep copy is possible only with user defined copy constructor.
*/
#include <iostream>
class Entity
{
    int val;

public:
    Entity()
    {
        val = 0;
        std::cout << "Default constructor\n";
    }
    Entity(int x)
    {
        val = x;
        std::cout << "Parameterized constructor\n";
    }
    Entity(const Entity &e)
    {
        this->val = e.val;
        std::cout << "Copy constructor\n";
    }
    Entity &operator=(const Entity &e)
    {
        this->val = e.val;
        std::cout << "Assigment operator\n";
        return *this;
    }
    void ShowVal()
    {
        std::cout << val << std::endl;
    }
};

int main()
{
    Entity e1(1);
    auto e2 = e1;
    e2.ShowVal();

    std::cout << "\n----------------------------\n";

    Entity e3;
    e3 = e2;
    e3.ShowVal();
}