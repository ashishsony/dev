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
        cout<<"\nBase(int)\n";
    }
    void fun(int a)
    {
        cout<<"\nA::fun(int)\n";
    }
    /*void fun(double a)
    {
        cout<<"\nA::fun(float)\n";
    }/**/
    void callPrivatefun2()
    {
        fun2();
    }
    private:
    virtual void fun2()
    {
        cout<<"\nPrivate A::fun2()\n";
    }
};
class B:public A
{
    int b;
    public:
    B()
    {}
    B(int b):b(b),A(b)
    {
        cout<<"\nDerived(int)\n";
    }
 /*   void fun(int a)
    {
        cout<<"\nB::fun(int)\n";
    }/**/
    using A::fun;/*this unhides the base class fun*/ /*makes every f available from A:: , also, overloading resolution only happens within a scope, this is why A::f is unavailable if its overloaded in B::*/
    void fun(double a)
    {
        cout<<"\nB::fun(float)\n";
    }
    /*private:
    void fun2()
    {
        cout<<"\nPrivate B::fun2()\n";
    }/**/
};
/*
Summary: dont overload in base and derived classes, overload in base, and let these overloads call protected virtuals which are not overloaded, so if derived need to override 
these virtuals, they can to define a different implementation.
 
 */
int main()
{
    //B bObj(1);
    A a;B b;
    A * aptr = &b;
    a.fun(1);
    a.fun(1.1);
    b.fun(1);
    b.fun(1.1);
    aptr->callPrivatefun2();
    a.callPrivatefun2();

    return 0;
}
