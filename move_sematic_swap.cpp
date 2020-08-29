#include <iostream>

template <typename T>
void swap(T& a, T& b){
	T tmp(std::move(b));
	b = std::move(a);
	a = std::move(tmp);
}


int main ()
{
	int a = 1, b = 2;

	std::cout << "a = " << a << ", b = "<< b << std::endl;

	swap (a,b);
	
	std::cout << "a = " << a << ", b = "<< b << std::endl;


}
