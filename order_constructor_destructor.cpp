#include <iostream>
using namespace std;

class Mobile{
    public:
        Mobile(){cout<<"Constructor: Mobile\n";}
        ~Mobile(){cout<<"Destructor : Mobile\n";}
};

class Tablet{
    public:
        Tablet(){cout<<"Constructor: Tablet\n";}
        ~Tablet(){cout<<"Destructor : Tablet\n";}
};

//Gadgets is the derived class using Multiple inheritance features with //Mobile and Tablet class
class Gadgets:public Mobile,public Tablet{
    public:
        Gadgets(){cout<<"Constructor: These are my Gadgets\n";}
        ~Gadgets(){cout<<"Destructor : Destroying Gadgets\n";}
};

//--------------------TEST--------------------------------------

/*
    Construtor: Top down
    Destrutor: Bottom up
*/
int main()
{
	Gadgets myGadgets; // create the object that will call required constructors	

	return 0;
}