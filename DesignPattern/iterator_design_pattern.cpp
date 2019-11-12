#include <iostream>
using namespace std;
// Item class
class Notification {
    string notifcation;
    public:
        Notification(string noti){
            this->notifcation = noti;
        }
        string getNotification(){
            return notifcation;
        }
};

// Iterator Interface
template <class T>
class Iterator {
    virtual bool hasNext() = 0;
    virtual T next() = 0;
};

// Iterator Implement
class NotificationIterator:public Iterator<Notification>{
    Notification NotificationList[10];
    int size;
    int pos;
    
    bool hasNext() {
        if (pos >= size)
            return false;
        return true;            
    }
    Notification next() {
        pos += 1;
        return NotificationList[pos];
    }
};

// Aggregate Interface
class Collection{
    public:
        virtual Iterator<Notification>* createIterator() = 0;
};

// Aggregate Implement
class NotificationCollection: public Collection {
    
    public:
    Iterator<Notification>* createIterator() {

    }

};

class NotificationBar {
    NotificationCollection notificationList;

};

int main(){


    cout<<"hello world"<<endl;

}

