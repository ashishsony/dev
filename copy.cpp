#include<iostream>
using namespace std;
struct A
{
    int a;
    int m(int);
};
int A::m(int a)
{
    cout<<"\n\na="<<a;
    return a;
}
template<typename Obj,typename mp,typename val>
void callIt(Obj obj,mp ptr,val v)
{
    int a=(obj.*ptr)(v);
}
int main()
{
    A a;
    callIt(a,&A::m,40);

    return 0;
}
