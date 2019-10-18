#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int *a,int start,int end)
{
    int pivot = a[end];
    int j = start;

    for (int i = start; i < end; i++ ){
        if (a[i] <= pivot){
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[end], a[j]);
    
    return j;    
}

 void Quicksort(int *a,int start,int end)
{
    if(start<end)
    {
         int P_index=partition(a,start,end);
             Quicksort(a,start,P_index-1);
             Quicksort(a,P_index+1,end);
    }
}

int main()
{
     int n = 8, a [n] = {12, 58, 1, 33, 8, 6, 21, 3};

      for(int i=0;i<n;i++)
      {
    	 cout<<a[i]<<" ";
      }
        cout<<endl;
      Quicksort(a,0,n-1);
      cout<<"After Quick Sort the array is:\n";
      for(int i=0;i<n;i++)
      {
    	 cout<<a[i]<<" ";
      }
      cout<<endl;
    return 0;
}