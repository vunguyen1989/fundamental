#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
struct A{
	int a;
	string x;
	A(int a1, string x1):a(a1), x(x1)
	{
	}
};

int main(){

	vector<A> v;
//	A x
	v.push_back(A(5, "conga"));
	v.push_back(A(8, "convit"));
	
	v.push_back({15, "con nga"});
	v.push_back({18, 4, "conbo"});
	//A* p = v.begin();//can not

	A* p = &v[0];

	cout << p->a << " - " << p->x << endl;



}
