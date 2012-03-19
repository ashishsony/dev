#include<iostream>
#include<pthread.h>
using namespace std;
struct A
{
    static void * fun(void * )
    {
        cout<<"\nfun from thr1\n";
    }
};
    A aa;
void* (*fptr) (void*);
int main()
{
fptr=aa.fun;
    int a;
    pthread_t  thr1;
    pthread_create(&thr1,NULL,fptr,0);
    pthread_join(thr1,(void**)&a);
    return 0;
}
