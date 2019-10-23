/*
Empty class means, a class that DOES NOT CONTAIN ANY DATA MEMBERS e.g. int a , float b and string etc. 
However, a class can contain member functions

    - the size of empty class in C++ with virtual function (4 or 8 bytes)because of virtual pointer i.e. VPTR. 
        When we make a function as a virtual, compiler automatically set a hidden VPTR as a class data member field. 
        So, no longer a class is an empty class that contains virtual function in C++.
    - and without virtual function (1 byte not 0 ) with reason and example. 1 byte for unique address identification
*/


#include <iostream>
using namespace std;

//Empty class
class EmptyClass{

};

//Empty class that contains only function
class EmptyClassWithFunctions{

	public:
        virtual void display(){
        // void display(){
        }
};

int main(){

	cout << sizeof(EmptyClass)<<endl;
	cout << sizeof(EmptyClassWithFunctions)<<endl;

	return 0;
}