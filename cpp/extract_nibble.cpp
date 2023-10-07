#include <iostream>
#include <array>


int main(){


  std::array<unsigned char, 4> x = {0x31, 0x32, 0x38, 0x80};
  std::array<unsigned char, 2> ret = {0x00, 0x00};
  ret[0] = (x[0]&(0x0f)) << 4 | x[1]&(0x0f);
  ret[1] = (x[2]&(0x0f)) << 4 | x[3]&(0x0f);

  for (int i = 0; i < 2; i++){
    printf("%.2X ", ret[i]);
  }
  std::cout << std::endl;
  



}
