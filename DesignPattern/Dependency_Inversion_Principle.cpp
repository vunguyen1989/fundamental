#include <iostream>
using namespace std;

class DB {
        // DB(){}
    public:
        // DB(){}
        virtual void conn () = 0;
};

class MySQL:public DB{
// class MySQL:DB{
    void conn(){
        cout<<"This is MySQL"<<endl;
    }
};

class PostelSQL:DB{
    void conn(){
        cout<<"This is PostelSQL"<<endl;
    }
};

class DBCofig
{
private:
    DB *db;
public:
    DBCofig(DB *db);
    ~DBCofig();
};

DBCofig::DBCofig(DB *db)
{
    this->db = db;
    cout<<"Here is DBConfig"<<endl;
}

DBCofig::~DBCofig()
{
}


int main(){
    MySQL msql;
    // msql.conn();
 
    DB *db = new MySQL(); // ERROR: ‘DB’ IS AN INACCESSIBLE BASE OF ‘MYSQL’
    db->conn();
    DBCofig dbconfig(db);
    return 0;
}

/*          INHERITANCE SPECIFICATION
    BASE CLS    PUBLIC          PRIVATE         PROTECTED

    Public	    Public	        Private	        Protected

    Private	    Inaccessible	Inaccessible	Inaccessible

    Protected	Protected	    Private	        Protected
*/

/*
    Base class can access the private driven method of driven class.
*/