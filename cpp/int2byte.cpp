#include <vector>
#include <array>
#include <iostream>
#include <cstring>
#include "boost/endian/conversion.hpp"
#include <boost/predef/other/endian.h>

using namespace std;

vector<unsigned char> intToBytes(int paramInt)
{
  vector<unsigned char> arrayOfByte(4);
  for (int i = 0; i < 4; i++)
    arrayOfByte[3 - i] = (paramInt >> (i * 8));
  return arrayOfByte;
}

template <size_t N, size_t DigitNo>
bool intToNibbles(uint64_t v, std::array<unsigned char, N>& arrayOfByte)
{
  uint64_t q = 0u;
  auto i = 0u;
  uint64_t mods[]{10u, 100u, 1000u, 10000u, 100000u, 1000000u, 10000000u, 100000000u, 1000000000u, 10000000000u, 100000000000u, 1000000000000u};
  uint64_t divs[]{1u, 10u, 100u, 1000u, 10000u, 100000u, 1000000u, 10000000u, 100000000u, 1000000000u, 10000000000u, 100000000000u};

  while ((i < DigitNo) && (v / divs[i]))
  {
    q |= ((v % mods[i]) / divs[i]) << (i << 2);
    ++i;
  }

  std::cout << "VuNN = " << i << std::endl;
/*  
  char arr[N] = {0};
  memcpy(arr, (char *)&q, sizeof(q));

  for (auto i = 0u; i < N; i++)
  {
    arrayOfByte[N - 1 - i] = arr[i];
  }
*/

  boost::endian::native_to_big_inplace<uint64_t>(q);
  
  memcpy(arrayOfByte.begin() + N - i/2 - 1, (unsigned char*)(&q) + sizeof(uint64_t) - i/2 - 1, i/2 + 1);

  if (i%2){
    arrayOfByte[N - i/2 - 1] = arrayOfByte[N - i/2 - 1] + 0xf0;
  }
  return true;
}

int main()
{
if(BOOST_ENDIAN_BIG_BYTE)
      std::cout << "Big endian." << std::endl;
if(BOOST_ENDIAN_LITTLE_BYTE)
      std::cout << "Little endian." << std::endl;

//  uint64_t n = 125689751315; //=> 12 56 89 75 13 15

  // uint64_t n = 5689751315;
  uint64_t n = 124;
//  std::cout << n << std::endl;

  //std::array<unsigned char, 6> v{0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  std::array<unsigned char, 6> v{};
  v.fill(0xff);
  for (auto i : v){
    printf("%.2x ", i);
  }
  std::cout << std::endl;
  intToNibbles<6, 12>(n, v);
  for (auto i : v)
  {
    printf("%.2x ", i);
  }
  std::cout << std::endl;
}
