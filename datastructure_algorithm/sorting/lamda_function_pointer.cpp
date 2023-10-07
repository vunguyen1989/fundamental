#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void PrintElement (int value){
    cout << value << endl;
}
void ForEach(vector<int> values, const std::function<void(int)> &func){
    for (int value : values) {
        // cout << value << " ";
        func(value);
    }
    cout << endl;

}

void HelloWorld (){
    cout << "hello world " << endl;
}

int main(){
    // Functon pointer
    // typedef void(*HelloWorldfunc)();
    // HelloWorldfunc f = HelloWorld;

    // f();
    // f();
    
    //LAmda: whenever you have a function pointer you can use it as a lamda
    vector<int> v = {4, 6, 8, 10};
    // ForEach(v, PrintElement);
    auto a = 100;
    auto lamda = [=](int element){ cout << element << "and a = "<< a << endl;};
    // ForEach(v, [](int element){cout << element << endl;});
    ForEach(v, lamda);
}