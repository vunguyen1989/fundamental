#include <queue>
#include <iostream>
#include <string>

using namespace std;

void showQueue(priority_queue<int, vector<int>, less<int>>& q){
    /*
    priority_queue doesn't allow iteration through all the members, presumably because it would be too easy 
    in invalidate the priority ordering of the queue (by modifying the elements you traverse) or maybe it's a "not my job" rationale.
    */    
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }
    
}
struct Person{
    int h;
    string name;
    bool operator< (const Person& p) const{
        return p.h > h;
    }

};

struct CompareHeigh{
    bool operator()(Person p1, Person p2){
        return p1.h < p2.h;
    }
};

int main(){
    priority_queue<int, vector<int>, less<int>> q;

    q.push(12);
    q.push(3);
    q.push(18);
    // showQueue(q);

    priority_queue<Person, vector<Person>> p_q;

    p_q.push({10, "a"});
    p_q.push({11, "b"});
    p_q.push({8, "c"});

    while (!p_q.empty()){
        Person p = p_q.top();
        cout << "name: " << p.name << " h : " << p.h << endl;
        p_q.pop();
    }
    return 0;
}