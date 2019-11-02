#include <iostream>

using namespace std;

/*      THIS POINTER
    - Wherever an OBJECT CALLS A CLASS MEMBER FUNCTION then compiler 
    INTERNALLY pass a THIS pointer to member function internally. 
    - This pointer make code readable

    - error: ‘this’ is UNAVAILABLE FOR STATIC MEMBER FUNCTIONS
*/
class Car{
	int model;
    static int a;
public:
	void SetModel(int model){		//=> 2 para: this, model
		// this->model = model;
		model = model; //still work fine => but not correct data
	}

    static void TestThisOnStatic(){
        // this->a = 0; // error: ‘this’ is unavailable for static member functions
        a = 5;
    }

    void ShowModel(){
        cout<< "Car model: " << model << endl;
    }
};

int main(){

	int modelNumber = 1024;
	Car obj;
	//On calling function using class obj
	//THIS pointer is also passed internally besides
	//model number paramer.
	obj.SetModel(modelNumber);
    obj.ShowModel();

	return 0;
}