#include <iostream>
#include <string>

std::string strString()
{
    return "This is a string";
}
int main()
{
    auto a = strString();
    std::cout << a << std::endl;

    auto &&b = strString();
    std::cout << b << std::endl;

    b[5] = 'X';
    std::cout << b << std::endl;
}