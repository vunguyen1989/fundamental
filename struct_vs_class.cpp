#include <optional>
#include <iostream>
#include <string>
#include <array>
#include <string_view>
class Name
{
    std::string name;

public:
    Name(std::string str)
    {
        std::cout << "Name Constructor\n";
    }
};

struct Employee
{
    Name name;
    int id;

public:
    Employee() {}
    Employee(std::string name_) : name{name_} {}
};

int main()
{
    std::array<Employee, 3> arr;
}