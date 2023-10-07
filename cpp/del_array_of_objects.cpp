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
//    Pen* pen = new Pen();
//    pen->write();//operations
//    delete pen;//de-allocate the memory 
    /* CONCULSION 1
        - we must delete it explicitly to avoid memory leaks in C++ programs after we are done with its operations.
    */   
    


//CREATE AN ARRAY OF OBJECTS
   Pen* penList = new Pen[3];

   penList[0].write();
   penList[1].write();
   penList[2].write();
   
   delete penList;//de-allocate only penList[0] --> call Destructor once then crash
//    delete [] penList;//de-allocate array of objects

    /* CONCULSION 2
        - You can only call delete[] on pointers returned by new[], and you must do this exactly once. 
        - The same applies for delete and new.
    */   

   return 0;
}