#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:    
    virtual void update() = 0;
};

class Logger:public Observer{
public:    
    void update(){
        cout<< "Logger updated. " << logger_name << endl;
    }

    Logger(string user_name){
        this->logger_name = user_name;
    }
private:
    string logger_name;    
};

class Mailer:public Observer{
public:
    void update(){
        cout<< "Mailer updated. " << mailer_name << endl;

    }
    Mailer(string user_name){
        this->mailer_name = user_name;
    }
private:
    string mailer_name;    
};

class Subject {
public:    
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify_all_observers() = 0;
};

class AccountService:public Subject {
public:
    AccountService (string name){
        this->user_name = name;
    }
    void attach(Observer* observer ){
        observers.push_back(observer);
    }
    void detach(Observer* observer){//todo: check lại logic chổ này
        observers.pop_back();        
    }
    void login(){
        cout<< user_name << " logined." << endl;
        notify_all_observers();
    }

private:
    void notify_all_observers(){
        for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++){
            (*it)->update();
        }
    }

private:
    string user_name;
    vector<Observer*> observers;    
};

int main(){
    AccountService acc1 = AccountService("vu ilts");
    acc1.attach(new Logger("vunn"));
    acc1.attach(new Mailer("vunn"));

    acc1.login();

    return 0;
}