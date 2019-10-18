#include <iostream>
using namespace std;
class A{
    int Id;
    public:
        A()
        {
            cout<<"Inside constructor"<<endl;
            Id=10;
        }
        A (const A &a)
        {
            cout<<"Inside copy constructor"<<endl;
            Id=10;
        }
        int GetId()
        {
            return Id;
        }
};
int main(){
    //Test object self assignment
    // Scenario 1:
    // A obj(obj); //Error : obj undeclared identifier

    // Scenario 2:
    //Below code is OK.
    A obj1; //declaration and initialization done here
    // A obj = obj1; // self assignment
    obj1 = obj1; // self assignment
    cout <<"Id is : "<<obj1.GetId()<< "\n";

    // Scenario 3:
    //A *a = new A(*a);// compiled but crashes on run time stating : variable 'a' is being use

    // Scenario 4:
    //Below code is ok.
    // A*a new A(); //declaration and initiazation done hereOutput:
    // A*a = new A(); //declaration and initiazation done here
    // a = new A(*a); // self assignment. Copy constructor will be called here.

    // cout <<"Id is : "<<a->GetId()<< "\n";
    return 0;
}