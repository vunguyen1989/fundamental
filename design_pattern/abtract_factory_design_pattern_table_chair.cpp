#include <iostream>
using namespace std;
enum MaterialType{
    WOOD, PLASTIC
};
//Abstract Chair
class Chair{
    public:
    virtual void CreateChair() = 0;
};
//Abstract Table
class Table{
    public:
    virtual void CreateTable() = 0;
};


class WoodenChair:public Chair
{
    void CreateChair(){
        cout<< "Wooden Chair"<<endl;
    }
};
class PlasticChair:public Chair
{
    void CreateChair(){
        cout<< "Plastic Chair"<<endl;
    }
};


class WoodenTable:public Table{
    void CreateTable()    {
        cout<<"Wooden table"<<endl;
    }
};
class PlasticTable:public Table{
    void CreateTable()    {
        cout<<"Plastic table"<<endl;
    }
};

//Abstract Factory
class AbstractFurnitureFactory{
public:
    virtual Table* CreateTable() = 0;
    virtual Chair* CreateChair() = 0;
    static AbstractFurnitureFactory* GetFactory(MaterialType type);
};

class WoodenFuniture:public AbstractFurnitureFactory{
    Table* CreateTable(){
        return new WoodenTable();
    }
    Chair* CreateChair(){
        return new WoodenChair();
    }
};
class PlasticFuniture:public AbstractFurnitureFactory{
    Table* CreateTable(){
        return new PlasticTable();
    }
    Chair* CreateChair(){
        return new PlasticChair();
    }
};


AbstractFurnitureFactory* AbstractFurnitureFactory::GetFactory(MaterialType type){
    switch (type)
    {
    case WOOD:
        return new WoodenFuniture();
    
    case PLASTIC:
        return new PlasticFuniture();
    
    default:
        cout<<"No supporting type = "<<type<<endl;
        return NULL;
    }
}

int main(){
    AbstractFurnitureFactory* factory = AbstractFurnitureFactory::GetFactory(PLASTIC);

    Chair* chair = factory->CreateChair();
    chair->CreateChair();

    Table* table = factory->CreateTable();
    table->CreateTable();

    return 0;
}