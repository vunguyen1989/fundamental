#include <iostream>

using namespace std;
class Example{
	public:
			Example(){

					cout << "Example Default constructor" << endl;
			}
			Example (int x){
					m_x = x;
					cout << "Example Parameterized constructor" << endl;
			}

	private:
			int m_x;
};

class Entity {
	public:
		Entity(){

			cout << "default constructor "<< endl;
		}
		Entity (int a):m_a(a),m_e(4) {
		//	m_a = a;
		//	m_e = Example(4);
			cout << "parameterize constructor" << endl;
		}

	private:
		int m_a;
		Example m_e;

};

int main(){

	Entity e(3);

}
