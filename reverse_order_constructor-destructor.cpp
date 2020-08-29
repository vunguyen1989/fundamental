#include <iostream>

using namespace std;

class Base {
	public:
			Base(){
				cout << "Base() " << endl;
			}

			~Base(){
				cout << "~Base() " << endl;
			}
};

class Drived: Base {
	public:
			Drived(){
				cout << "Drive()" << endl;
			}
			~Drived(){
				cout << "~Drive()" << endl;
			}
};

int main(){
	Drived d;

}
