#include <iostream> 

using namespace std; 

class Complex 
{ 
    private: 
        double real; 
        double imag; 

    public: 
        // Default constructor 
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {} 
        // explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {} 

        // A method to compare two Complex numbers 
        bool operator == (Complex rhs) { 
            return (real == rhs.real && imag == rhs.imag)? true : false; 
        } 
}; 

int main() 
{ 
	// a Complex object 
	Complex com1(3.0, 0.0); 

    /*
        if a class has a constructor which can be CALLED WITH A SINGLE ARGUMENT, 
        then this constructor becomes CONVERSION CONSTRUCTOR because such a constructor allows conversion 
        of the single argument to the class being constructed.
    */
	


	// if (com1 == 3.0) //avoid such IMPLICIT CONVERSIONS as these may lead to unexpected results => Explicit keyword in constructor
    if (com1 == (int)3) //with EXPLICIT in constructor => (Complex) to EXPLICITLY typecast
    	cout << "Same"; 
	else
	    cout << "Not Same"; 
	return 0; 
} 
