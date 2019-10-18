#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Cache {
    int cache_size;
    unordered_map<string, string> mKeyValue;
    unordered_map<string, list<string>::iterator> mKeyListIt;
    list<string> qKey;
    
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


            unordered_map<string, string>::iterator it = mKeyValue.find(key);
            if (it != mKeyValue.end()){//if found the key
                qKey.erase(mKeyListIt[key]);
                qKey.push_front(key);

                mKeyListIt.erase(key);
                mKeyListIt.insert({key,qKey.begin()});
            } else //if not found
            {
                if (mKeyValue.size() == cache_size){ // if the cache is full, remove the oldest one
                    mKeyValue.erase(qKey.back());
                    mKeyListIt.erase(qKey.back());
                    qKey.pop_back();
                }
                qKey.push_front(key);
                mKeyListIt.insert({key, qKey.begin()});
                mKeyValue.insert({key, value});
            }
            
            mKeyValue.erase(key);
            mKeyValue.insert({key, value});
            return 0;
        }

        string get(const string &key){
            //check key
            if (key == ""){
                cout<<"invalid key"<<endl;
                return "";
            }
            if ( mKeyValue.find(key) == mKeyValue.end() ) {//not found
                return "";
            } else { //found
                string value = mKeyValue[key];
                unordered_map<string, list<string>::iterator>::iterator it = mKeyListIt.find(key);
                if (it != mKeyListIt.end()){//if found the key
                    qKey.erase(it->second);
                    qKey.push_front(key);
                    mKeyListIt.insert({key, qKey.begin()});
                } else
                {
                    cout<<"something wrong, pls recheck the logic, key = "<< key << endl;
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
            if ( mKeyValue.find(key) == mKeyValue.end() ) {
                return -1;
            } else { //found
                mKeyValue.erase(key);
                qKey.erase(mKeyListIt[key]);
                mKeyListIt.erase(key);
            }
            return 0;
        }

        void show_cache(){
            for (unordered_map<string, string>::iterator it = mKeyValue.begin(); it != mKeyValue.end(); it++){
                cout << it->first << " : " << it->second <<"\n";
            }
        }

        void show_key(){
            cout<<"show key -------"<<endl;
            for (list<string>::iterator it = qKey.begin(); it != qKey.end(); it++){
                cout << *it <<endl;
            }
        }
};


int main(){
    Cache cache(5);

    cache.add("a", "con ga");
    cache.add("b", "con bo");
    cache.get("a");
    cache.add("d", "qua oi");
    cache.get("b");
    cache.get("a");
    cache.add("1001", "may tinh");
    cache.add("1002", "may bay");
    cache.del("b");
    cache.add("a", "con ga");
    
    

    
    cache.show_cache();
    cache.show_key();

    return 0;
}