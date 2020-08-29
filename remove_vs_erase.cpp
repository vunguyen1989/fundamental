#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void Print (T t, string message){
	cout << message << ": { " ;
	for (auto it = t.begin(); it != t.end(); it++)
	{
			cout << *it << ", ";
	}
	cout << "}" << endl;
}

int main(){

	list<int> v = { 1, 3, 0, 12, 1, 5, 1, 19, 16 };
	string str("Origin");
	Print(v,str);

	
//	auto it = remove(v.begin(), v.end(), 1);	
//	
//	
//	string afterRemove ("After Remove");
//	Print(v, afterRemove);
//
//	v.erase(it, v.end());
//
//	string after ("After Remove then Erase");
//	Print(v,after);
	
/*
	cout << "Capacity of vector : " << v.capacity() << endl;

	v.shrink_to_fit();
	cout << "Capacity of vector after shrink_to_fit(): " << v.capacity() << endl;

	string s ("after shrink");
	Print(v, s);
*/


}
