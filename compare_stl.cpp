#include <map>
#include <iostream>
#include <set>

using namespace std;




int main(){

    set<pair<string, int>, mycomp<pair<string, int>>> mymap;

    mymap.insert({"a",20});
    mymap.insert({"vunguyen",31});
    mymap.insert({"long",15});

    for (auto element: mymap){
        cout << element.first << " \t \t \t - " << element.second << endl;
    }

    return 0;
}