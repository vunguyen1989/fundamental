#include <stdlib.h>
#include <stdio.h>

int compare (const void* a, const void* b){
    int x = *((int*)a);
    int y = *((int*)b);
    return x - y;
}

int main(){
    int n = 6, A[] = {1, 2, -9, 4, 0, 3};

    qsort(A, 6, sizeof(int), compare);

    for (int i = 0; i < 6; i++){
        printf ("%d ", A[i]);
    }
    printf("\n");
}
