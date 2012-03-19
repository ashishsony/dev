#include<iostream>
using namespace std;
class Base
{
    public:
    Base()
    {
        cout<<"\nBase()";
    }
    ~Base()
    {
        cout<<"\n~Base()";
    }
    virtual void f()
    {
    }
};
class D1:public Base
{
    public:
    D1()
    {
        cout<<"\nD1()";
    }
    ~D1()
    {
        cout<<"\n~D1()";
    }
};
classA
{
//int i;
virtual void f();
//char c;
};
class AA
{
int i;
char c;
};
int main()
{
    D1 d;
    cout<<"\n\nsizeof(A)"<<sizeof(A);

}

