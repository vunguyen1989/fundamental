#include <iostream>
using namespace std;

class Unique {
    private:
        Unique(){
            cout<< "Unique Constructor"<<endl;
        }
    public:
        ~Unique(){
            cout<< "Unique Destructor"<<endl;
        }
        static Unique* GetInstance (){
            Unique *instance = new Unique();
            return instance;
        }
        void ShowUnique(){
            cout<<"Hi, this is Unique"<<endl;
        }
        friend class Test;
};

class Test {
    
    public:
        void ShowTest (){
            Unique u;
            u.ShowUnique();
        }
};

class Derived:public Unique{
    public:
        // Derived(){
        //     cout<<"Derived constructor"<<endl;
        // }

    public:
        void Display(){
            cout<<" My Derived Class"<<endl;
        }
};

int main(){

    // Unique::GetInstance()->ShowUnique();
    Unique* u = Unique::GetInstance();
    u->ShowUnique();
    delete u;
    // Derived d;
    // d.Display();
    // Test t;
    // t.ShowTest();

    return 0;
}