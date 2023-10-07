#include <iostream>
#include <vector>
using namespace std;
#pragma optimize( "", off )
/* unoptimized code section */
// #pragma optimize( "", on )
class X
{
public:
	~X(){
		cout << "Destructor" << endl;
	}
	X()
	{
		cout << "Default contructor" << endl;
	}
 
	X(const X& lvalue)
	//  = delete;// copy constructor
	{
		cout << "Copy contructor" << endl;
		// [...]
		// Hủy tài nguyên (vùng nhớ) m_pResource đang trỏ tới
		// Tạo một vùng nhớ mới có giá trị như rhs.m_pResource đang trỏ tới
		// Gán vùng nhớ vừa tạo cho con trỏ m_pResource
		// [...]
	}
	//[...]

	// move constructor
	// X(X&& rvalue)
	// {
		
	// 	cout << "Move constructor" << endl;
	// 	// [...]
	// 	// Hoán đổi vùng nhớ của this->m_pResource và rhs.m_pResource
	// 	// [...]
	// }
};
 
X foo()
{
	X x;
	//[...]
	std::cout << "foo" <<endl;
	return x;
}
 #pragma optimize( "", on )
int main()
{

	X x1 = foo();
	cout << "main" << endl;
	// vector<X> vec;
	// vec.push_back(X());
}