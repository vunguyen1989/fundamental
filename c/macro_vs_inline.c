#include <stdlib.h>

#define SQRT(X) (X * X)

static inline int sqrt(x){return x*x;}
/*  WHEN USING INLINE
    - small function
    - frequently call


*/
int main(){

    int x = 3;
    int y = SQRT(++x);// ->  SQRT(4) -> 5 * 5 = 25
    

    printf("%d\n", y); //=> 25 : sai

    x = 3;
    y = sqrt(++x); 
    printf("%d\n", y);  //=> 16

    return 0;
}

