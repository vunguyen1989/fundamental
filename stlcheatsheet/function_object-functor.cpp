#include <iostream>

using namespace std;

class X {

    public:
        void operator () (string str){
            cout << "The string is : " << str << endl;
        }
};

int main(){
    X foo;
    foo("Hi");
}