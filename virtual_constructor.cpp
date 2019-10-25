#include <iostream>

using namespace std;

/*
    - As a good design practice WE NEED TO WRITE C++ VIRTUAL DESTRUCTOR 
    until we are very sure that there is no need to make destructor virtual.
    =>TO AVOID MEMORY LEAK

*/
class Base{
    public:
        // virtual Base (){cout << "Base constructor"<<endl;} //=> error: constructors cannot be declared virtual [-fpermissive]
        // inline Base (){cout << "Base constructor"<<endl;} //inline okie
            Base (){cout << "Base constructor"<<endl;}

};

class Derived:public Base{
    public:
        Derived (){cout << "Derived constructor"<<endl;}
};

int main(){
    // Base* base = new Derived();//upcasting
    // delete base; //=> WE HAVE TO USE VIRTUAL DESTRUCTOR

    // Derived* d = new Derived();
    // delete d;

    // Derived d;
    // return 0;
}