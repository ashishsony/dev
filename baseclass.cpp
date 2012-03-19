#include<iostream>
using namespace std;
class A
{
    public:
    int a;
    A()
    {
        cout<<"\nBase default\n";
    }
    A(int a):a(a)
    {
        cout<<"\nBase\n";
    }
};
class B:public A
{
    int b;
    public:
    B(int b):b(b),A(b)
    {
        cout<<"\nDerived\n";
    }
};
int main()
{
    B bObj(1);
    return 0;
}
