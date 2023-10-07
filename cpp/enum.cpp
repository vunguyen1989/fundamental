#include <iostream>

enum Example {
	A, B, C
};

class Entity {
public:
	enum Level {
		Error, Debug, Info
	};


};
int main(){
	Example a = A;
	std::cout << a << std::endl;	


	Entity::Level logLevel = Entity::Level::Error;
	std::cout << "log level = " << logLevel << std::endl;
}
