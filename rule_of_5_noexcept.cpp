#include <cstring>
#include <algorithm>

class Person
{
    char *name;
    int age;

public:
    // Destructor
    ~Person() { delete[] name; }
    Person() noexcept = default;
    // Implement Copy Semantics
    Person(Person const &other)
        : name(new char[std::strlen(other.name) + 1]), age(other.age)
    {
        std::strcpy(name, other.name);
    }

    Person &operator=(Person const &other)
    {
        // Use copy and swap idiom to implement assignment.
        Person copy(other);
        swap(*this, copy);
        return *this;
    }

    // Implement Move Semantics
    // Note: It is usually best to mark move operators as noexcept
    //       This allows certain optimizations in the standard library
    //       when the class is used in a container.

    Person(Person &&that) noexcept
        : name(nullptr) // Set the state so we know it is undefined
          ,
          age(0)
    {
        swap(*this, that);
    }

    Person &operator=(Person &&that) noexcept
    {
        swap(*this, that);
        return *this;
    }

    friend void swap(Person &lhs, Person &rhs) noexcept
    {
        std::swap(lhs.name, rhs.name);
        std::swap(lhs.age, rhs.age);
    }
};

int main()
{
    Person p1;
    Person p2 = p1;
    return 0;
}