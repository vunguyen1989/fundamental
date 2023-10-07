#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> v = {2, 5, 3, 1, 8};
    auto it = find_if(v.begin(), v.end(), [](int element){return element > 3;});
    cout << "find_if :" << *it << endl;

    auto cnt = count_if(v.begin(), v.end(), [](int element){return element > 3;});
    cout << "cnt = " << cnt << endl;
    sort(v.begin() + 1, v.begin() + 3, [](int element1, int element2){
        return element1 > element2;    
    });

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}