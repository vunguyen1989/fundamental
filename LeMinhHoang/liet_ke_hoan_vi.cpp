#include <iostream>
#include <algorithm>
using namespace std;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void PrintHoanVi(int x[], int n){
    for (int i = 0; i < n; i++){
        cout<<x[i];
    }
    cout<<endl;
}

int main(){
    int n;
    cin >> n;

    // Cau hinh dau tien: 1234
    int x[n] = {0};
    for (int i = 0; i < n; i++){
        x[i] = i + 1;
    }
    PrintHoanVi(x, n);
    /* THUAT TOAN SINH CAU HINH KE TIEP
        Tim đọan cuoi giam dan: x[i][doan cuoi giam dan: x[j]...]; x[j]>x[i]
        Trong [doan cuoi giam dan], chọn ra x[k] > x[i]
        Swap (x[i], x[k])
        Trong [doan cuoi giam dan], sap xep tang dan
        Khi khong con [doan cuoi giam gan nua] => ket thuc cau hinh
    */

   int i = n - 1, m = 0;
   while (i > 0)
   {
       if (x[i-1] > x[i]){
           m++;
           i--;
       } else
       {
           i = n - 1 - m - 1;
           int j = n - 1;
           while(x[i] > x[j]){
               j--;
           }
           Swap(x[i], x[j]);
           sort(x + i + 1, x + n);
           PrintHoanVi(x, n);
           i = n - 1;
           m = 0;
       }
   }
    // Cau hinh cuoi cung: 4321
    return 0;
}