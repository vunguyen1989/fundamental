#include <iostream>
#include <vector>

int main(){

	std::vector <int> v = {1, 2, 3, 4};

	std::cout << v.size() << " - " << v.capacity() << std::endl;

	v.push_back(5);

	std::cout << v.size() << " - " << v.capacity() << std::endl;
	v.clear();

	std::cout << v.size() << " - " << v.capacity() << std::endl;

	v.push_back(5);


	std::cout << v.size() << " - " << v.capacity() << std::endl;

	v.resize(6);

	std::cout << "After resize() " << std::endl << v.size() << " - " << v.capacity() << std::endl;
	
	v.reserve(20);
	std::cout << "After resize() " << std::endl << v.size() << " - " << v.capacity() << std::endl;

}
