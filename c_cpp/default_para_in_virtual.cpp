#include <iostream>

class Base {
  public:
  virtual  void f(int a = 7) = 0;
};

class Drived : public Base {
  public:
  void f(int a = 5) override;
};

void Drived::f(int a){
    std::cout << "a = " << a << std::endl;
}

int main(){
  Drived d;
  d.f();
//  Base* b = &d;
//  b->f();
}
