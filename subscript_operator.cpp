#include <iostream>
#include <unordered_map>

using namespace std;
void foo(const unordered_map<char, int>& m){
	//cout <<	m['s'] << endl; // will raise an compile error, because subscript operator in map means you're about to modify the element
	auto it = m.find('s');
	if (it != m.end()){
		cout << it->second << endl;
	} else {
		cout << "element not found" << endl;
		
	}
}

int main(){
	unordered_map<char, int> m;
	m.insert (make_pair('s', 1989));
	foo(m);
}
