#include <iostream>
using namespace std;
/*
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34
    1) return F(n)
    2) return F(n) using recursion
*/

//slide window technique
int findFiboSum(int n){
    int f1 = 0, f2 = 1;
    int sum = 0, temp, step = 1;
    if (n == 0){
        return sum;
    }
    while (step <= n){
        sum += f2;
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        step++;
    }
    return sum;
}

//recursion technique
int findFiboN(int n){
    if (n == 0){
        return 0;
    } 
    if (n == 1){
        return 1;
    } else
    {
        return findFiboN(n -1) + findFiboN(n - 2);
    }
}

int main(){
    int n = 3;
    // cout<< findFiboN(n) << endl;
    // cout << findFiboN(6) << endl;
    cout<< findFiboSum(4) << endl;
}