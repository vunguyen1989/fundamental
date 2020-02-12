#include <iostream>

using namespace std;

void A (){
    cout << "Hello" << endl;
}

void foo (void(*p)()){

    p();
}


int main (){
    auto x = &A;

    foo(x);

}