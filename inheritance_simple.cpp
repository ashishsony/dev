#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
class A
{
    int a;
    protected:
    int b;
    public:
    int c;
    void fun()
    {
        cout<<"\nfunA\n";
        int a=1;
    }
};
class B :public A
{
    int d;
    protected:
    int e;
    public:
    int f;
    void fun()
    {
        cout<<"\nfunB\n";
        int a=0;
    }
    using A::fun;
};
class Q
{
    char a;
    static char x;
};
int main()
{
    B objb;
    objb.fun();
    /*B objb;
    objb.f=1;
    objb.e=1;
    objb.b=1;
    map<string,int> MAP;
    MAP["ashish"]=1;
    MAP["ashish"]+=1;
    cout<<"MAP[ashish]::"<<MAP["ashish"];*/
    cout<<"\nsizeof(B)::"<<sizeof(Q);
    cout<<"\nsizeof(A)::"<<sizeof(A);

}
