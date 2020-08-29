#include <iostream>


using namespace std;
class Entity{
	int m_a;
	int m_b;
	int* m_pC;
public:
	Entity(){}
	Entity(int a, int b, int c):m_a{a}, m_b{b}, m_pC{new int}{
		*m_pC = c;
	}
	~Entity(){

		delete m_pC;
	}
	Entity(const Entity& e){
		m_a = e.m_a;
		m_b = e.m_b;
		m_pC = new int;
		*m_pC = *(e.m_pC);

	}
	Entity operator= (const Entity& rhs){
		if (this != & rhs){
			m_a = rhs.m_a;
			m_b = rhs.m_b;
			m_pC = new int;
			*m_pC = *(rhs.m_pC);
		}
		return *this;

	}
	void ShowEntity(){
		cout << "m_a = "<< m_a << "; m_b = " << m_b <<"; *m_pC = " << *m_pC << endl;
	
	}
	friend void SetPointer (Entity& e, int c);


};

void SetPointer(Entity& e, int c){
	*(e.m_pC) = c;
}
int main(){

	Entity e(1,2,3);
	Entity e2(1,2,4);
	Entity e1;
       	e1 = e = e2;

	e1.ShowEntity();

	SetPointer(e, 5);

	e1.ShowEntity();


}
