#include <iostream>
class A
{
private:
    int *arr_;
    std::size_t size_;

public:
    A() : size_{3}
    {
        std::cout << "Default constructor" << std::endl;

        arr_ = new int[size_];
        for (int i = 0; i < size_; i++)
        {
            arr_[i] = i + 1;
        }
    }

    A(unsigned int n = 3) : size_{n}
    {
        std::cout << "Parameter constructor" << std::endl;
        arr_ = new int[size_];
        for (int i = 0; i < size_; i++)
        {
            arr_[i] = i + 1;
        }
    }

    A(const A &rhs)
    {
        size_ = rhs.size();
        arr_ = new int[size_];
        for (int i = 0; i < size_; i++)
        {
            arr_[i] = rhs.arr_[i];
        }
        std::cout << "Copy constructor" << std::endl;
    }

    A(A &&rhs)
    {
        arr_ = rhs.arr_;
        rhs.arr_ = nullptr;
        std::cout << "Move constructor" << std::endl;
    }

    ~A()
    {
        delete[] arr_;
        std::cout << "Destructor" << std::endl;
    }

    std::size_t size() const
    {
        return size_;
    }
};

A CreateA()
{
    A ret(3);
    return ret;
}

void foo(A a)
{
    std::cout << "Foo\n";
}

void foo_left_ref(A &a)
{
    std::cout << "Foo with Left ref\n";
}

void foo_right_ref(const A &&a)
{
    std::cout << "Foo with Right ref\n";
}

int main()
{
    A usableA = CreateA();
    foo(usableA);
    // foo_left_ref(usableA);
    foo(std::move(usableA));
}
