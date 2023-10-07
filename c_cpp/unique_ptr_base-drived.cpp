#include <iostream>
#include <memory>
#include <vector>

struct Base
{
};

struct Derived : public Base
{
};

int main()
{
    std::unique_ptr<Derived> derivedObject;
    std::vector<std::unique_ptr<Base>> vec;

    vec.push_back(std::move(derivedObject));
}