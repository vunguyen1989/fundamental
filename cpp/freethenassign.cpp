#include <iostream>

int main()
{
	int* p = new int();
	delete p;
	*p = 10;

	std::cout << "*p = " << *p << std::endl;
	return 0;
}
