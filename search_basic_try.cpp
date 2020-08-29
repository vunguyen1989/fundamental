#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
	vector<int> v {1, 2, 4, 8, 5, 3};

	sort(v.begin(), v.end(), [](const auto& e1, const auto& e2){return e1 > e2;});
	for (auto i: v){
		cout << i << " ";
	}
	cout << endl;
	cout << (binary_search(v.begin(), v.end(), 3, greater<int>()) ? "Found" : "Not Found") << endl;

	
}
