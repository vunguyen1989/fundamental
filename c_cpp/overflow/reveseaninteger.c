#include<stdio.h>


int reverse(int x) {
        if (x > 2147483647)
            return 0;
        if (x < (-2147483648))
            return 0;
        int digit = 0, minusFlag = 1;
        unsigned int ret = 0;
        if (x < 0){
            x = x * (-1);
            minusFlag = -1;
        }
        while (x > 0){
            digit = x % 10;
                ret = ret*10 + digit;
            x = x/10;
        }
        return ret*minusFlag;
}

int main(){

    int n = -729;

    printf("ret = %d\n", reverse(n));

}