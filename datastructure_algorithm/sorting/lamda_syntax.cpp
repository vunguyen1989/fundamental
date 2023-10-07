#include <iostream>
#include <functional>

using namespace std;

int main(){

    // [](int val){
    //     cout << "something funny " << val <<  endl;
    // }(100);

    function<void(int)> func = [](int val){
        cout << "something funny " << val <<  endl;
    };

    // func(50);

    int i = 4, n = 2;
    cout << "n = " << n << "; i = " << i << endl;

    [&n, i] (int val) mutable {
        n = 3;
        i--;
        cout << "val = " << val << "; n = " << n << " and i = " << i << endl;
    }(100);

    cout << "n = " << n << "; i = " << i << endl;
    return 0;
}