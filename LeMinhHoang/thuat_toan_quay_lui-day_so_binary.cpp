#include <iostream>
using namespace std;

//vi du: n = 3 => 000, ..., 111
int n = 2;
int arr[3];

void PrintArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i];
    }
    cout<<endl;
}

void Attempt(int i){
    // for (int j = 0; j < 2; j++){
    //     arr[i] = j;
    //     if (i == n){
    //         cout<< "j = "<< j << endl;
    //         PrintArray(arr, n);
    //     } else {
    //         // cout<< "i = "<< i << " j = "<< j << endl;
    //         Attempt(i+1);
    //     }
    // }
    int j=0;
    while(j < 2){
        arr[i] = j;
        if (i == n){
            cout<< "j = "<< j << endl;
            PrintArray(arr, n);
        } else {
            // cout<< "i = "<< i << " j = "<< j << endl;
            Attempt(i+1);
        }
        j++;
    }
}

int main(){
    Attempt(0);
    return 0;
}