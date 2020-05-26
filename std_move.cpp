#include <iostream>


void swap(int& a, int& b)
{
    int tmp(std::move(a));
    std::cout << "a = " << std::move(a) << std::endl;
    a = std::move(b);   
    std::cout << "b = " << b << std::endl;
    b = std::move(tmp);
}

class A {
  private:
  int* arr;

  public: 
  A(const A& rhs){
    std::cout << "Copy constructor" << std::endl;
  }

  ~A(){
    delete[] arr;
  }



};



int main (){
/*
  int a = 3, b = 7;
  
  std::cout << "a = " << a << ", b = " << b << std::endl;
  
  swap(a,b);

  std::cout << "a = " << a << ", b = " << b << std::endl;
*/


}
