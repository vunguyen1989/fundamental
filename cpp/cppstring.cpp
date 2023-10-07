#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Constructors
	string s1("Hello abc");
	cout <<"s1 :" << s1 << endl;

	string s1_2(s1,2);
	cout << "(s1,2) : " << s1_2 << endl;

	string s1_2_3(s1, 2, 3);
	cout << "(s1, 2, 3) : " << s1_2_3 << endl;

	string s2 = string("Hello", 3);
	cout <<	"(\"Hello\", 3) \t\t: " << s2 << endl;;
	
	string s3 = {'a', 'b', 'c'};
	cout << "s3 = " << s3 << endl;

	string s4 (5, 'a');
	cout << "(5, 'a') : " << s4 << endl;

	//size vs length, capacity
	//reserve vs resize
	//shrink_to_fit
	cout << "s1 capacity: "<< s1.capacity() << endl << "s1 size: " << s1.size() << endl << "s1.length() :" << s1.length() << endl;
	s1.shrink_to_fit();
	cout << "s1 capacity after shrink_to_fit : " << s1.capacity() << endl;
	



}
