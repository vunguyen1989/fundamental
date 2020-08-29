#include <iostream>

using namespace std;

// struct Entity {
//     static int x, y;
//     static void print (){
//         cout << " x = "<< x <<", y = " << y << endl;
//     }
// };

// static void print (Entity e){
//         cout << " x = "<< e.x <<", y = " << e.y << endl;
// }

class A {

// public:
    virtual void vf1(){
        cout << "vf1 in class A" << endl;
    }
public:    
    void f1() {
        cout << "f1() in class A" << endl;
        vf1();

    }

};

class B : public A{
    void vf1(){
        cout << "vf1 in class B" << endl;
    }
};

int main(){
    A a;
    a.f1();
cout << "-----------" << endl;
    B b;
    b.f1();
}