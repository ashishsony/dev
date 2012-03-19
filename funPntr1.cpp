#include<iostream>
using namespace std;
struct A
{
    int a;
    int fun(int);
};
int A::fun(int)
{
    cout<<"a="<<a;
}
int main()
{
    int (A::*fp)(int)=&A::fun;
    A a;
    (a.*fp)(1);
    return 0;
}

