#include <iostream>
#include <vector>

using namespace std;

template <class T, class U>
class Iterator{
public:    
    typedef typename vector<T>::iterator it_def;
    Iterator(U u){
        this->u = u;
        m_data_it = u.m_data.begin();
    }

    it_def begin(){
        return u.m_data.begin();
    }

    it_def end(){
        return u.m_data.end();
    }

    bool isDone(){
        return m_data_it == u.m_data.end();
    }

    it_def next(){
        return m_data_it++;    
    }

    it_def current(){
        return m_data_it;    
    }
private:
    it_def m_data_it;
    U u;
};

template <class T>
class Aggregate {
public:
    void add(T element){
        m_data.push_back(element);
    }
    Iterator<T,Aggregate> create_iterator(){
        return Iterator<T, Aggregate>(*this);
    }
    friend class Iterator<T, Aggregate>;

private:
    vector<T> m_data;

};

class Integer{
    int x;
public:    
    Integer(int n):x(n){}
    void showInteger(){
        cout<< x << endl;
    }

};

int main(){
    Aggregate<Integer> agg;
    agg.add(Integer(3));
    agg.add(Integer(4));
    agg.add(Integer(5));
    
    Iterator<Integer, Aggregate<Integer> > it = agg.create_iterator();
    for (it.begin(); !it.isDone(); it.next()){
        it.current()->showInteger();
    }
        

    return 0;
}