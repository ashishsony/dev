#include<iostream>
using namespace std;
struct A
{
    void m(int);
};
void A::m(int x)
{
    cout<<"\n\nX:"<<x<<"\n\n";
}
template< typename methodPtr ,typename arg>
void callMethod(A& a,methodPtr mp,arg val)
{
    (a.*mp)(val);
}
int main()
{
    A aObj;
    callMethod(aObj,&A::m,40);
    return 0;
}
