#include <iostream>
#include <array>

class A {

  int x;
  int y;
};
int main(){

  std::array<A, 10> as;
  for (auto a = as.begin(); a != as.end(); a++)
  {

    std::cout << "index = " << a - as.begin() << std::endl;

  }







}
