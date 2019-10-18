#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
int main(){
    int a5[5] = {1, 2, 3, 4, 5};
    int temp, n;
    cout<< "times of rotations:  ";
    cin >> n;

    cout<<"Before rotating: ";
    for (int i = 0; i < 5; i++){
        cout << a5[i] << " ";
    }
    cout<<endl;
    //O(n)*O(d)
    // for (int i = 0; i < n; i++){
        // temp = a5[0];
        // for (int i = 1; i < 5; i++){
        //     a5[i - 1] = a5[i];
        // }
        // a5[4] = temp;
        
    // }

    //O(n), space O(d)
    int d[n] = {0};
    for (int i = 0; i < 5; i++){
        if (i < n){
            d[i] = a5[i];
            a5[i] = a5[i + n];
        } 
        if (i >= 5 - n){
            a5[i] = d[i - (5-n)];
        } else {
            a5[i] = a5[i + n];
        }
    }

    //O(n), space O(1)

    
    for (int i = 0; i < 5; i++){
        cout << a5[i] << " ";
    }
    cout<<endl;

    return 0;
}