#include <iostream>
#include <string>
using namespace std;

bool isPalidrome(const string &s){
    const char *sChar = s.c_str();
    for (int i = 0; i < s.size()/2; i++)    {
        if (sChar[i] != sChar[s.size()- 1 - i]){
            // cout << sChar[i] << " vs " << sChar[s.size() - i]<<endl;
            return false;
        }
    }
    // cout<<s<<endl;
    return true;
}

int main(){
    string str = "ab1ba";
    // string str = "a1a";
    string subString;
    int cntPalidrome = 0;
    for (int i = 0; i < str.length(); i++){
        for (int len = 1; len <= str.length() - i; len++){//check all possible strings that including the str[i] above
            subString = str.substr(i, len); //substr(index, len)
            cout<<"sub string = " << subString << endl;
            if (isPalidrome(subString)){
                cout<< subString <<endl;
                cntPalidrome += 1;
            }
        }
    }
    cout << cntPalidrome <<endl;
    return 0;
}