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
    virtual void fun()
    {
        cout<<"\nfunA\n";
        a=1;
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
        b=0;
    }
    void fun2()
    {
        //A::a = 44;
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
    A& Aref = objb;
    objb.fun();
    /*B objb;
    objb.f=1;
    objb.e=1;
    objb.b=1;
    map<string,int> MAP;
    MAP["ashish"]=1;
    MAP["ashish"]+=1;
    cout<<"MAP[ashish]::"<<MAP["ashish"];*/
    cout<<"\nsizeof(B)::"<<sizeof(B);
    cout<<"\nsizeof(A)::"<<sizeof(A);
//    cout<<"\nobjb.a"<<objb.fun();
    //objb.fun2();
    Aref.fun();

}
