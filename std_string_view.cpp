#include <string>
#include <iostream>

int main(){
	constexpr auto v = std::string_view("ga trong gay le te le te roi ai oi");

	auto sub_v = v.substr(2, 4);
	std::cout << sub_v << std::endl;

}

