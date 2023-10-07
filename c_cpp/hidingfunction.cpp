#include <iostream>

class Base {
	int m_Int;
public:
	void foo (int a, int b) {
		std::cout << "Base" << std::endl;
	}

};

class Drived: public Base {
public:
	using Base::foo;
	void foo(int a) {
		std::cout << "Drived" << std::endl;
	}
	
};

int main(){

	Drived d;
	d.foo('c');
	d.foo(1005);
	d.foo (5, 9);



}
