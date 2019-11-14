#include <iostream>
using namespace std;

//vi du: n = 3 => 000, ..., 111
void PrintArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout<<arr[i];
    }
    cout<<endl;
}


void Attempt(int i, int j, int k, int n, int* arr){
    for (; j <= n ; j++) {
        arr[i] = j;
        if (i == k - 1){ 
            PrintArray(arr, k);
        } else {
            Attempt(i + 1, j + 1, k, n, arr);
        }
    }
}

int main(){
    int n, k = 3;
    printf("nhap n : ");     // nhap n
    scanf("%d", &n);
 
    int arr[k];
    Attempt(0, 1, k, n, arr);
    return 0;
}