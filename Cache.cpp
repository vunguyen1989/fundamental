#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Cache {
    int cache_size;
    map<string, string> m;
    vector<string> vRecentKey;
    
    public:
        Cache(int n){
            cache_size = n;
        }
        int add(const string &key, const string &value){
            //check key
            if (key == ""){
                cout<<"invalid key"<<endl;
                return -1;
            }

            vector<string>::iterator it = std::find(vRecentKey.begin(), vRecentKey.end(), key);
            if (it != vRecentKey.end()){//if found the key
                vRecentKey.erase(it);
                vRecentKey.push_back(key);
            } else //if not found
            {
                if (vRecentKey.size() < cache_size){ // if the cache is not full
                    vRecentKey.push_back(key);
                }
                else // if the cache is full: delete the oldest key
                {
                    vRecentKey.erase(vRecentKey.begin());                    
                    vRecentKey.push_back(key);
                }
            }
            
            m[key] = value;
            return 0;
        }

        string get(const string &key){
            //check key
            if (key == ""){
                cout<<"invalid key"<<endl;
                return "";
            }
            if ( m.find(key) == m.end() ) {//not found
                return "";
            } else { //found
                string value = m[key];
                vector<string>::iterator it = std::find(vRecentKey.begin(), vRecentKey.end(), key);
                if (it != vRecentKey.end()){//if found the key
                    vRecentKey.erase(it);
                    vRecentKey.push_back(key);
                } 
                return value;
            }
        }

        int del(const string &key){
            //check key
            if (key == ""){
                cout<<"invalid key"<<endl;
                return -2;
            }
            // not found
            if ( m.find(key) == m.end() ) {
                return -1;
            } else { //found
                m.erase(key);
                vector<string>::iterator it = find(vRecentKey.begin(), vRecentKey.end(), key);
                vRecentKey.erase(it);
            }
            return 0;
        }

        void show_cache(){
            for (map<string, string>::iterator it = m.begin(); it != m.end(); it++){
                cout << it->first << " : " << it->second <<"\n";
            }
        }

        void show_key(){
            cout<<"show key -------"<<endl;
            for (vector<string>::iterator it = vRecentKey.begin(); it != vRecentKey.end(); it++){
                cout << *it <<endl;
            }
        }
};


int main(){
    Cache cache(3);

    cache.add("a", "con ga");
    cache.add("b", "con bo");
    cache.get("a");
    cache.add("d", "qua oi");
    cache.get("b");
    // cache.get("a");
    cache.add("1001", "may tinh");
    cache.add("1002", "may bay");
    cache.del("b");
    // cache.add("a", "con ga");
    
    

    
    cache.show_cache();
    cache.show_key();

    return 0;
}