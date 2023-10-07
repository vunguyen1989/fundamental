#include <iostream>
#include <thread>
#include <string>

class Ftor{
public:
	void operator()(std::string& msg){
		std::cout << "from t1: " << msg << std::endl;
	    msg = "the trust is mother of deceit";	
	}
};

void function_1(){
	for (int i = 0; i > -100; i--){
		std::cout << "from function_1: " << i << std::endl;
	}
}

int main() {
	std::string s = "there is no trust, there is no love";
	std::thread t1((Ftor()), std::move(s));
	t1.join();
	std::cout<< "from main: " << s << std::endl;
	return 0;
}
