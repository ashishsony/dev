#include<iostream>
using namespace std;
class exceptA{};
class exceptB{};
class exceptC{};
void funA() throw (exceptA)
{
    throw exceptA();
}
void funB() throw(exceptB)
{
    throw exceptB();
}
void funC() throw (exceptC)
{
    throw exceptB();
}
class A
{
    public:
    A(){cout<<"A()\n";}
    ~A(){cout<<"~A()\n";}
};
class B
{
    public:
    B() throw(exceptB)
    {
        cout<<"B()\n";
        throw exceptB();
    }
    ~B(){cout<<"~B()\n";}
};
class C
{
    public:
    C() //throw(exceptB)
    {
        cout<<"C()\n";
    }
    ~C(){cout<<"~C()\n";}
    A a;
    B b;
};
int main()
{
    try
    {
    C c;
    }
    catch(...)
    {
    cout<<"\nException!!!!\n";
    }
/*    try{
    funA();
    }
    catch(exceptA)
    {
        cout<<"ExceptionA\n";
    }
    try{
    funB();
    }
    catch(exceptB)
    {
        cout<<"ExceptionB\n";
    }
    try{
    funC();
    }
    catch(exceptC)
    {
        cout<<"ExceptionC\n";
    }
    */
    return 0;
}

