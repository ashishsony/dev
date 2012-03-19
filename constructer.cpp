#include<iostream>
using namespace std;
class A
{
    public:
        A();
        A(int a);
        A(const A&);
        A& operator=(const A&);
        int a;

};
A::A():a(0)
{
    cout<<"A()\n";
}
A::A(int a):a(a)
{
    cout<<"A(a)\n";
}
A::A(const A& copy)
{
    cout<<"operator= \n";
    a=copy.a;
}
A& A::operator=(const A& eq)
{
    a=eq.a;
    return *this;
}
int main()
{
    A a1;
    A a2=4;
    a1=a2;
cout<<"a1.a="<<a1.a<<"\n";
cout<<"a2.a="<<a2.a<<"\n";

}
