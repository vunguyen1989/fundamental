#include <sys/time.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include <unordered_map> 
#include<algorithm>

using namespace std;
int main(){
    set <int> s;
    unordered_set<int> unordered_s;
    vector <int> v;
    map <int, int> m;
    unordered_map <int, int> unordered_m;

    int x = 0, y = 0, n;
    cin>>n;
    for (int i = 0; i < n; i++){
        x = rand()%50000;
        y = rand()%90000;

        s.insert(x);
        unordered_s.insert(x);
        
        m.insert({x, y});
        unordered_m.insert({x, y});
        
        v.push_back(x);
    }
    
    struct timeval t0,t1;
    gettimeofday(&t0, 0);
        vector<int>::iterator it = find(v.begin(), v.end(), 1760);
    gettimeofday(&t1, 0);

    long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Vector \t\t:" << elapsed <<endl;

    sort(v.begin(), v.end());
    gettimeofday(&t0, 0);
        bool t_f = binary_search(v.begin(), v.end(), 1760); //bool type in return
    gettimeofday(&t1, 0);
    elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Sorted Vector \t:" << elapsed <<endl;

    gettimeofday(&t0, 0);
        set<int>::iterator si = s.find(1760);
    gettimeofday(&t1, 0);
    elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Set \t\t:" << elapsed <<endl;

    gettimeofday(&t0, 0);
        unordered_set<int>::iterator unordered_si = unordered_s.find(1760);
    gettimeofday(&t1, 0);
    elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Unordered Set \t:" << elapsed <<endl;

    gettimeofday(&t0, 0);
        m.find(1760);
    gettimeofday(&t1, 0);
    elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Map \t\t:" << elapsed <<endl;

    gettimeofday(&t0, 0);
        unordered_map<int, int>::iterator unordered_map_it = unordered_m.find(1760);
    gettimeofday(&t1, 0);
    elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
    cout<<"Unordered Map \t:" << elapsed <<endl;

    return 0;
}