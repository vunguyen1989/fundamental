#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Entity {
	string m_name;
public:
	//shared_ptr<Entity> m_spEntity;
	weak_ptr<Entity> m_spEntity;

	Entity(string name):m_name(name){
		cout << "Created Entity, name = " << name << endl;
	}	

	~Entity(){
		cout << "Destroy Entity, name = " << m_name << endl;
	}
};

int main(){
	
	shared_ptr<Entity> sp_E1(new Entity("Ga"));
	shared_ptr<Entity> sp_E2(new Entity("Vit"));

	sp_E1->m_spEntity = sp_E2;
	sp_E2->m_spEntity = sp_E1;




}
