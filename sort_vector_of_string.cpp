#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main()
{
	std::vector<std::string> v;

	v.push_back("acd");
	v.push_back("ccd");
	v.push_back("a");
	v.push_back("bbdcd");
	v.push_back("1agwi2");

	for (auto i : v) 
		std::cout << i << std::endl;

	for (auto i : v){
		std::sort(i.begin(), i.end());
	}

	std::sort(v.begin(), v.end());
	std::cout << "After sorting" << std::endl;

	for (auto i : v){
		std::cout << i << std::endl;
	}	
}
