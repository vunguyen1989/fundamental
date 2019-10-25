#include <iostream>
#include <memory>
using namespace std;

enum SHAPETYPE{
	CIRCLE,
	SQUARE,
	RECTANGLE
};

//Shape classes
class IShape{
public:
	void virtual draw()=0;
};

class Circle:public IShape{
	void draw(){
		cout<<"Circle"<<"\n";
	}
};
class Square:public IShape{
	void draw(){
		cout<<"Square"<<"\n";
	}
};
class Rectangle:public IShape{
	void draw(){
		cout<<"Rectangle"<<"\n";
	}
};

class ShapesFactory{
public:

	//Factory method that returns instance of multiple type
	//of shapes
	static IShape* getInstance(SHAPETYPE Type){

		if( Type == CIRCLE){
			return new Circle;
		}else if( Type == SQUARE){
			return new Square;
		}else if( Type == RECTANGLE){
			return new Rectangle;
		}
	}
};


// Smart Pointers
//Shape Smart Pointer
class SPShape{

	IShape *_pointer;
public:
	SPShape(IShape *pointer):_pointer(pointer){		
	}

	// call delete on shape pointer
	~SPShape(){
		cout<<"Deleting object"<<"\n"; delete _pointer; } //overload "*" in case we need to deference object. IShape& operator* () { return *_pointer; } //Overload -> operator that will be used to 
	//call functions of classes
    IShape* operator-> ()
    {    
        return _pointer;
    }
};

void TestFunction(){

	//Get Circle object
	// SPShape cptr = ShapesFactory::getInstance(CIRCLE);
	SPShape cptr(ShapesFactory::getInstance(CIRCLE));
	cptr->draw();

	// Get square object
	// SPShape sptr = ShapesFactory::getInstance(SQUARE);
	// sptr->draw();

	//When Test function ends these objects will go out of scope
	//and destructor of SPShape will be automatically called and object
	//will get deleted.

}

//Use Auto_pointer : This is the smart pointer provide std name space.

// need to include #include header file.

//An auto_ptr is simply an object that holds a pointer for us within a function.
//Holding a pointer to guarantee deletion at the end of a scope is what auto_ptr is for
void TestAuto_ptr(){
	std::auto_ptr<IShape> cir(ShapesFactory::getInstance(SQUARE));
	cir->draw();	
}

int main(){

	TestFunction();	//Test implemented smart pointer
	TestAuto_ptr();// Test auto_ptr
	
	return 0;
}
