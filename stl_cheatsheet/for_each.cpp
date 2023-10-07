#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void add2 (int& x){
    // cout << x + 2 << endl;
    x = x + 2;
}

template <int val>
void addVal (int& x){
   x = x + val; 
}

int main(){

    vector<int> v {1, 2, 3, 4};

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    cout << "-------" << endl;
    
    // for_each (v.begin(), v.end(), add2);

    // int x = 2;
    for_each (v.begin(), v.end(), addVal<2>);

    //using functor
    
    cout << "-------" << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    return 0;
}