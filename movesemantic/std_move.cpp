#include <iostream>

void swap(int &a, int &b)
{
  int tmp(std::move(a));
  a = std::move(b);
  b = std::move(tmp);
}

int main()
{
  int a = 3, b = 8;
  std::cout << "a = " << a
            << ", b = " << b << std::endl;
  swap(a, b);
  std::cout << "a = " << a
            << ", b = " << b << std::endl;
}