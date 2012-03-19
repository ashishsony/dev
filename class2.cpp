
#include<iostream>
using namespace std;
class A
{
    public:
        //virtual void a();
        //virtual ~A();
        A(const A& );
        A();
        A(A*);
};
A::A(A* a)
{
    *this=*a;
}
A::A()
{
    cout<<"\n\nA::A()";
}
A::A(const A& a)
{
    cout<<"\n\n A:: copy ctor";
}
class B:public A
{
};
int main()
{

    A* a=new A();
    A* p=new A(*a);
    A obj(*p);
    A obj2=obj;
    A obj3=A();
}
