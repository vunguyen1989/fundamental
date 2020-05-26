#include <iostream>
int my_var;

int & foo (){
  return my_var;

}

int add5(const int& a){
  return a + 5;
}

int main(){
  foo() = 50;
  std::cout << my_var << std::endl;  

  add5(3);

}
