#include <iostream>
#include <string>

using namespace std;

int reverse_string(char* s, int i, int n){
    if (i == n - 1){
        cout << s[i];
    } else
    {
        reverse_string(s, i+1, n);
        cout << s[i];
    }
}

int main(){
    string s = "abcd1234";
    reverse_string((char*)s.c_str(), 0, s.size());
    return 0;
}