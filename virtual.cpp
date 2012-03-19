#include<iostream>
using namespace std;
class A
{
    public:
        int a;
        virtual void fun()
        {
            cout<<"A::fun()\n";
        }
};
class B:public A
{
    public:
        int b;
};
        void B::fun()
        {
            cout<<"B::fun()\n";
        }
int main()
{
    B bobj;
    A& aobj=bobj;
    aobj.fun();
    bobj.A::fun();

}
