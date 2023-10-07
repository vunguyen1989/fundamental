#include <iostream>

using namespace std;

int main(){
    // int x = 21022012;
    int x = 2012;
    int temp = x, b = 0;

    while (temp > 0){
        int endDigit = temp%10;
        temp = temp / 10;
        b = b*10 + endDigit;
    }

    if (b == x){
        cout << "YES" <<endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
}