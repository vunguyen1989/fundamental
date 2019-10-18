#include <iostream>
#include <deque> 
#include <algorithm>
using namespace std;

void printKMax(int arr[], int n, int k){
	int *max;
    for (int i = 0; i < n - k + 1; i++){
        
        for (int j = i; j <= k - 1 + i; j++){
            cout<< arr[j]<< " ";
        }
        max = std::max_element(&arr[i], &arr[k + i]);
        cout<< " => max = " << *max <<endl;
    }
    
}

int main(){
    // int arr [5] = { 3, 5, 8, 9, 17};
    int arr [7] = { 3, 4, 5, 8, 1, 4, 10};

	int n = 7, k = 4;
    printKMax(arr, n, k);
    
  	return 0;
}

