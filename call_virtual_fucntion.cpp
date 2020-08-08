//  g++ call_virtual_fucntion.cpp -lpthread
// https://tombarta.wordpress.com/2008/07/10/gcc-pure-virtual-method-called/

#include <pthread.h>
#include <unistd.h>
struct base
{
    virtual ~base() {
        sleep(1);
    }
    virtual void func() = 0;
};
struct derived : public base
{
    virtual ~derived() { }
    virtual void func() {
        return;
    }
};
static void *thread_func(void* v)
{
    base *b = reinterpret_cast<base*>(v);
    while (true) b->func();
    return 0;
}
int main()
{
    pthread_t t;
    base *b = new derived();
    pthread_create(&t, 0, thread_func, b);
    delete b;
    return 0;
}