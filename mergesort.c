/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    //init 2 array: L & R, luu y cac array nay da duoc sap xep
    int L_size = m - l + 1,
        R_size = r - m;
    int L[L_size], R[R_size];

    for (int a = 0; a < L_size; a++){
        L[a] = arr[l + a];
        // printf("L[%d] = %d   ", a, L[a]);
    }
    
    for (int b = 0; b < R_size; b++){
        R[b] = arr[m + 1 + b];
        // printf("R[%d] = %d   ", b, R[b]);
    }

    printf("\n\n");
    int k = l, i = 0, j = 0;
    //merge 2 array nay vao array "arr" ban dau
    while (i < L_size && j < R_size)
    {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    //copy phan con lai neu co cua array L vao arr
    while (i < L_size)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //copy phan con lai neu co cua array R vao arr
    while (j < R_size)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
        mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
		merge(arr, l, m, r); 
	} 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {12, 10, 13, 5, 2, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	printf("Given array is \n"); 
	printArray(arr, arr_size); 

	mergeSort(arr, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
} 
