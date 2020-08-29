#include <iostream>
#include <memory>
using namespace std;
class MyInt{
	int* data;

	public:
		
		MyInt(int* p = NULL){
			data = new int[10];	
			cout << "Constructor of MyInt is called" << endl;
		}

		~MyInt(){
			delete data;
			cout << "destructor of MyInt is called" << endl;
		}
		int& operator* (){
			return *data;
		}	


};

class Entity{
	public:
		Entity(){
			cout << "call Entity constructor" << endl;
		}
		~Entity(){
			cout << "call Entity destructor" << endl;
		}
		void print(){
			cout << "print Entity" << endl;
		}
};

int main(){
//
	// int* p = new int[10];
	// cout << "*p = " << *p << endl;
	// cout << "sizeof p = " << sizeof(p) << endl;

	// MyInt myint(p);
	// cout << "*myint = " << *myint << endl;

//unique pointer	
	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>();
		entity->print();
		std::unique_ptr<Entity> e2 = move(entity);
	}

//shared pointer
	std::shared_ptr<Entity> shareE0;
	{
		std::shared_ptr<Entity> sharePtr = std::make_shared<Entity> ();
		shareE0 = sharePtr;
	}
	cout << "After Shared scope" << endl;


}
