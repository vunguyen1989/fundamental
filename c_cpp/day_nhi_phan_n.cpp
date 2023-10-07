#include <iostream>

using namespace std;

void PrintBinary(char x[], int n){
    for (int i = 0; i < n; i++){
        cout<<x[i];
    }
    cout<<endl;
}
int main(){
    int n;
    cin >> n;

    // Cau hinh dau tien: 00000
    char x[n] = {0};
    for (int i = 0; i < n; i++){
        x[i] = '0';
    }
    PrintBinary(x, n);

    // Thuat toan sinh cau hinh ke tiep
    int i = n-1;
    while(i>=0){
        if (x[i] == '0'){
            x[i] = '1';
            int j = i + 1;
            while (j < n)
            {
                x[j] = '0';
                j++;
            }
            PrintBinary(x, n);
            i = n - 1;
        }
        if (x[i] == '1'){
            i--;
        }
    }
    // Cau hinh cuoi cung: 11111
    return 0;
}