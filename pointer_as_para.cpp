/* 
    [x] just copy when passed a pointer into a pointer parameter
*/
#include <iostream>
void PointerPara(int *&p)
{
    p = new int(3);
}

int main()
{
    //Pointer as a parameter
    int *ptr = NULL;
    printf("value of ptr = %p\n", ptr); //nil
    PointerPara(ptr);
    printf("value of ptr = %p\n", ptr); //nil
}