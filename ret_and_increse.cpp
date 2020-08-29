#include <iostream>

int inc(bool b){
  static  int a = 9;
  if (b){
    a = a + 1;
    std::cout << "true, a = " << a << std::endl;
    return a++;
  } else {
    std::cout << "false, a = " << a << std::endl;
    return 0;
  }
}


int main(){
  int c = inc(true);
  std::cout << "ret = <<" << c << std::endl;
  inc(false);
  return 0;
}
