#include <type_traits>
#include <iostream>

template<std::size_t N>
std::enable_if_t <N <= 11, bool> get(){
  std::cout << "Something funny \n";
  return true;
}

int main (){
  get<10>();
}
