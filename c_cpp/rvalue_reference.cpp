#include <iostream>
#include <string>


std::string StrResource(){
	return "This is a string resource";
}

int main(){
	std::string& a = StrResource();
	std::cout << a << std::endl;

	std::string&& b = StrResource();
	std::cout << "rvalue ref b = " << b << std::endl;
}

