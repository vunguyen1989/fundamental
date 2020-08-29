#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;
char firstNotRepeatingCharacter(std::string s) {
    std::list<char> l;
    unordered_map<char, std::list<char>::iterator> m; 
    for (auto c : s) {
        auto it = m.find(c);
        if (it != m.end()){
            if (it->second != l.end()) {
                l.erase(it->second);
                m[c] = l.end();
            }
        } else {
            l.push_front(c);
            m.insert({c, l.begin()});
        }
    }
    for (auto i : l){
        cout << i << " ";
    }
    cout << endl;
    if (l.size() == 0){
        return '_';
    } else
        return l.back();
}

int main(){

    auto c = firstNotRepeatingCharacter("abacabaabacaba");
    cout << c << endl;
}
