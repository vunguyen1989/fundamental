#include <iostream>
using namespace std;

void PrintK(int K[], int k){
    cout<<"{";
    for (int i = 0; i < k-1; i++){
        cout << K[i] << ", ";
    }
    cout<<K[k -1]<<"}"<<endl;
}

int main(){
    int N[5] = {1, 2, 3, 4, 5};
    const int k = 3;
    int Kmax[k] = {0}, K[k] = {0};

    /*
        cai dat chuoi nho nhat 
        int K[3] = {1, 2, 3}
    */
   for (int i = 0; i < k; i++){
       K[i] = N[i];
       Kmax[i] = N[5 - k + i];
   }
    PrintK(K, 3);

   /* LOOP K[2] -> K[0]
        sinh chuoi ke tiep
   */
  int i = k - 1;
  while (i > 0)
  {
      //   K[i] max
      if (K[i] == Kmax[i]){
          i--;
      } 

      //K[i] < max
      if (K[i] < Kmax[i]){
          K[i]++;
          int j = i+1;
          while (j < k)
          {
              K[j] = K[j-1] + 1;
              j++;
          }
          PrintK(K, k);
          i = k - 1;
      }
  }
  return 0;
}