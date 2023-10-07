#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    vector <int> v = {9, 10, 11, 12, 10, 15};

//COUNT
    int cnt10 = count(v.begin(), v.end(), 10);

    cnt10 = count_if (v.begin(), v.end(), [](int x){return x > 10;});
    cout << cnt10 << endl;  

    
}