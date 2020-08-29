#include <iostream>
#include <vector>

using namespace std;

bool Compare (int a, int b){
    return a < b;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int selectionSort(vector<int>& v, bool (*comp)(int a, int b)){
    for (int i = 0; i < v.size() - 1; i++){
        for (int j = i + 1; j < v.size(); j++){
            if (comp(v[i], v[j])){    
                swap(v[i], v[j]);
            }
        }
    }
    return 0;
}

void showVector(const vector<int> v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {1, 20, 4, 69, 0, 9, 15};
    cout << "Befor sort: ";
    showVector(v);
    selectionSort(v, Compare);
    cout << "After sort: ";
    showVector(v);
    cout << endl;
}