#include <iostream>
#include <string>

int main(){
	std::string s1;
	s1.assign(3, 'x');
	std::cout << s1 << std::endl;

	s1.append(" def");
	std::cout << "after append \" def\":" << s1 << std::endl;

	s1.insert(2, "mountain");
	std::cout << "after inserting \"moutain\":" << s1 << std::endl;






}
