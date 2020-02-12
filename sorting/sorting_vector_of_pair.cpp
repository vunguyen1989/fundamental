#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool sortbysec(pair<string, int> e1, pair<string, int> e2){
    return e1.second > e2.second;
}
int main(){
    map<string, int> m;
    m.insert(make_pair("aa", 1));
    m.insert(make_pair("ac", 1));
    m.insert(make_pair("b", 3));
    m.insert(make_pair("b1", 3));
    m.insert(make_pair("x", 2));

    //sorting 1st
    vector<pair<int, string>> v1;
    vector<pair<string, int>> v2;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        v1.push_back(make_pair((*it).second, (*it).first));
        v2.push_back(make_pair((*it).first, (*it).second));
    }

    cout << "SORT BY FIRST" << endl;
    sort (v1.begin(), v1.end(), greater <>());
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i].second << " : " << v1[i].first << endl;
    }

    cout << "SORT BY SECOND" << endl;
    sort (v2.begin(), v2.end(), sortbysec);
    for (int i = 0; i < v1.size(); i++){
        cout << v2[i].first << " : " << v2[i].second << endl;
    }
}