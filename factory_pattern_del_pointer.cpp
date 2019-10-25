#include <iostream>
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

int main(){


	//Get shapes from factory without using smart pointer
	IShape * circlePtr = ShapesFactory::getInstance(CIRCLE);
	
	IShape * Squarptr = ShapesFactory::getInstance(CIRCLE);

	//Explicitly call delete to deallocate memory.
	delete circlePtr;
	delete circlePtr;	
	
	return 0;
}