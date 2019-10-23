#include <iostream>
using namespace std;

class PreventNewOnHeap{
    void* operator new(size_t n);
    int cnt;
    // public:
        PreventNewOnHeap(int x){
            cnt = x;
        }
    public:        
        PreventNewOnHeap operator+(const PreventNewOnHeap &p1){
            PreventNewOnHeap p(0);
            p.cnt = cnt + p1.cnt;
        }
        void ShowCnt(){
            cout<< cnt<<endl;
        }

        // void* operator new(size_t n){
        //     PreventNewOnHeap p(1);
        //     return &p;
        // }
};


int main(){
    // PreventNewOnHeap p1(1), p2(2);
    // PreventNewOnHeap p = p1 + p2;
    // p.ShowCnt();

    PreventNewOnHeap* p_p = new PreventNewOnHeap(4);


    return 0;
}