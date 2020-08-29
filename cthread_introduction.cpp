#include <iostream>
#include <thread>

void func(){
	std::cout << "Beauty is only deep skin" << std::endl;
}

int main(){
	std::thread t1(func);
	t1.detach();

	if (t1.joinable())
		t1.join();

	return 0;


}
