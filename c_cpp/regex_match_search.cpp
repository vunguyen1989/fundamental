#include <regex>
#include <iostream>
#include <string>

int main()
{

	std::regex e("abc", std::regex::icase);
	std::string str;

	std::cin >> str;
	
	bool match = std::regex_match(str, e);
	std::cout << ((match == true) ? "match" : "not match") << std::endl;
	
	bool search_match = std::regex_search(str, e);
	std:: cout << ((search_match == true)? "search match" : "search not match") << std::endl;
}

