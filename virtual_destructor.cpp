#include <iostream>

using namespace std;

/*
    - As a good design practice WE NEED TO WRITE C++ VIRTUAL DESTRUCTOR 
    until we are very sure that there is no need to make destructor virtual.
    =>TO AVOID MEMORY LEAK

*/
class Base{
    public:
        Base (){cout << "Base constructor"<<endl;}
        ~Base(){cout<<"Base class destructor..."<<"\n";}//=> only Base Destructor is called => memory leak ON HEAP
        // virtual ~Base(){cout<<"Base class destructor..."<<"\n";} 

};

class Derived:public Base{
    public:
        Derived (){cout << "Derived constructor"<<endl;}
        ~Derived(){cout << "Derived Destructor..."<<"\n";}//It won't be called IF NO VIRTUAL in Base()
};

int main(){
    // Base* base = new Derived();//upcasting
    // delete base; //=> WE HAVE TO USE VIRTUAL DESTRUCTOR

    // Derived* d = new Derived();
    // delete d;

    // Derived d;
    // return 0;
}