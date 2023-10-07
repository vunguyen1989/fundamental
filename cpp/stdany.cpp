#include <iostream>
#include <any>

int main()
{
	std::any a = 5;
	a = "forever";
	std::cout << a << std::endl;

	return 0;

}
