/*
1) How to delete array of objects in C++? 
2) Proof by C++ code for proper deletion
*/

#include <iostream>
using namespace std;

class Pen {
  
public:
      Pen() { 
         cout << "Constructor..." <<endl; 
      }
		
      ~Pen() { 
         cout << "Destructor...!" <<endl; 
      }
	  void write(){
		  cout << "Writing...!" <<endl; 
	  }
};

int main()
{
//CREATE AN OBJECT DYNAMICALLY
   Pen* pen = new Pen();
   pen->write();//operations
   
   delete pen;//de-allocate the memory
   
   return 0;
}