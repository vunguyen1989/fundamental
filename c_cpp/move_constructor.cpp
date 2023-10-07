#include <iostream>

class X {
	private:
			int *m_pInt;
	public:
			X(){
				std::cout << "Default Constructor" << std::endl;
			}
			X(const X& x){
				this->m_pInt = new int;
				std::cout << "Copy constructor" << std::endl;
			}
			
			X(X&& x){
				this->m_pInt = x.m_pInt;
				x.m_pInt = NULL;
				std::cout << "Move constructor" << std::endl;
			}
			
			~X(){
				std::cout << "Destructor " << std::endl;
			}

};

X foo(){
	X x;
	std::cout << "foo function" << std::endl;
	return x;
}

int main(){

	X x = std::move(foo());

}
