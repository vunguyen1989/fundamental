#include <stdio.h>
 
void quayLui(int i, int n, int *X)
{
    int val;    // val la cac gia tri co the gan cho cac vi tri trong X
    for (val = 0; val < 2; val++)      // val co the nhan hai gia tri la : 0 va 1
    {
        X[i] = val;
 
        if (i == (n-1))         // neu i la phan tu cuoi cua day
        {
            int j;
            for(j = 0; j < n; j ++)         // in ra day so nhi phan moi tim duoc
            {
                printf("%d", X[j]);
            }
            printf("\n");
        }
 
        else              // neu i chua phai phan tu cuoi thi ta se gan gia tri cho phan tu sau i.
        {
            quayLui(i+1, n, X);
        }
    }
}
 
 
int main()
{
    int n;
    printf("nhap n : ");     // nhap n
    scanf("%d", &n);
 
    int X[n];     // khai bao mang X co do dai n - chuoi nhi phan do dai n
 
    quayLui(0, n, X);  // goi ham xu ly quay lui
 
    return 0;
}