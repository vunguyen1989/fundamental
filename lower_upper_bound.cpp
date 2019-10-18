// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
      std::cout << *it <<" ";
  }
  std::cout<<std::endl;

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound 20 at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound 20 at position " << (up - v.begin()) << '\n';

  return 0;
}