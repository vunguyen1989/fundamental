#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

    int arr [] = {1, 3, 8, 2};

    int* begin = arr;
    int* end = arr + sizeof(arr)/sizeof(int);

    sort (begin, end, [](int i1, int i2){
        return i1 > i2;
    });

    for (; begin != end; begin++){
        cout << "value of arr = " << *begin << endl;
    }

    vector<int> l;
    l.push_back(15), l.push_back(13), l.push_back(41), l.push_back(4);
    
    sort(l.begin(), l.end());


    return 0;
}