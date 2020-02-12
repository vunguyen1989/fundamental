#include <iostream> 
#include <string> 
#include <vector>

using namespace std; 
  
int main() 
{ 
    string str = "forgeeks a computer science"; 
    string str1 = "geeks"; 
  
    vector<string> v;
    v.push_back(str);
    for (vector<string>::iterator it = v.begin(); it != v.end(); it++){
        size_t found = (*it).find(str1); 
        if (found != string::npos) 
            cout << "Found : " << str1 << endl;
    }

    // Find first occurrence of "geeks" 
    size_t found = str.find(str1); 
    if (found != string::npos) 
        cout << "First occurrence is " << found << endl; 
  
    // Find next occurrence of "geeks". Note here we pass 
    // "geeks" as C style string. 
    // char arr[] = "geeks"; 
    // found = str.find(arr, found+1); 
    // if (found != string::npos) 
    //     cout << "Next occurrence is " << found << endl; 
  
    // return 0; 
} 