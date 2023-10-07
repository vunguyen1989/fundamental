#include <iostream>
#include <vector>
using namespace std;

class Strategy{
public:    
    virtual void sort() = 0;
    Strategy(){
        cout<< "Strategy Constructor" <<endl;
    }
    virtual ~Strategy(){
        cout<< "Strategy Destructor" <<endl;
    }
};

class SelectionSort:public Strategy{
public:
    void sort(){
        cout<< "Slection Sort" << endl;
    }
    SelectionSort(){
        cout<< "Selection Sort Constructor" << endl;
    }
    ~SelectionSort(){
        cout<< "Selection Sort Destructor" << endl;
    }
};

class QuickSort:public Strategy{
public:
    void sort(){
        cout<< "Quick Sort" << endl;
    }
    QuickSort(){
        cout << "Quick Sort Constructor" << endl;
    }
    ~QuickSort(){
        cout << "Quick Sort Destructor" << endl;
    }
};

class Client {
    vector<int> vInt;
public:
    void add(int i){
        vInt.push_back(i);
    }
    void SortingList(Strategy* strategy){
        strategy->sort();
    }
};

int main(){
    Client cli;
    cli.add(1);
    cli.add(5);
    cli.add(3);
    
    Strategy* str = new SelectionSort();
    cli.SortingList(str);
    delete str;

    cout << endl;

    str = new QuickSort();
    cli.SortingList(str);
    delete str;
}