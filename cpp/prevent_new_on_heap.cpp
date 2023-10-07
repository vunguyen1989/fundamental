/*
    [] list of operators that can be overloaded
        +	-	*	/	%	^
        &	|	~	!	,	=
        <	>	<=	>=	++	--
        <<	>>	==	!=	&&	||
        +=	-=	/=	%=	^=	&=
        |=	*=	<<=	>>=	[]	()
        ->	->*	new	new []	delete	delete []
    [] list of operator that can NOT be overloaded
        ::	.*	.	?:
    [x] how to prevent new on heap
        1) put the function prototype in private
        2) using delete keyword
*/

#include <iostream>
using namespace std;
class PreventNewOnHeap
{
    void *operator new(size_t n);
    int cnt;
    // public:
    // PreventNewOnHeap(int x){
    //     cnt = x;
    // }
public:
    PreventNewOnHeap operator+(const PreventNewOnHeap &p1)
    {
        PreventNewOnHeap p;
        p.cnt = cnt + p1.cnt;
    }
    void ShowCnt()
    {
        cout << cnt << endl;
    }
    // void *operator new(size_t n) = delete;
};

int main()
{
    // PreventNewOnHeap p1(1), p2(2);
    // PreventNewOnHeap p = p1 + p2;
    // p.ShowCnt();

    PreventNewOnHeap *p_p = new PreventNewOnHeap();

    return 0;
}