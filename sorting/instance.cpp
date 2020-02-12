#include <iostream>

using namespace std;

void inc(int& x){
    x++;
}
int main(){
    int a = 5;

    int& ref = a;

    cout << ref << endl;
    inc(ref);

    cout << sizeof(ref) << endl;


}