#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	int arr[] = {1 , 4, 2, 0, 5};
	sort(arr, arr + sizeof(arr)/sizeof(int));
	for (int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
}
