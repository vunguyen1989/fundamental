#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v;

    v.push_back(20), v.push_back(10), v.push_back(200), v.push_back(120), v.push_back(70), v.push_back(40), v.push_back(40), v.push_back(20);

    for (auto &e : v){
        cout << "vector element = " << e << endl;
    }
    cout << "vector size before remove = " << v.size() << endl;

    // auto it = remove_if(v.begin(), v.end(), [](int val){
    //    if (val == 40) return true;
    //    else return false;
    // });

    auto it = remove(v.begin(), v.end(), 40);
    cout << "vector size after remove = " << v.size() << endl;

    v.erase(it, v.end());
    cout << "vector size after erase = " << v.size() << endl;

    // cout << "new size = " << it - v.begin() << "and *it = " << *it << endl;
    for (auto &e : v){
        cout << "vector element = " << e << endl;
    }

    return 0;
}