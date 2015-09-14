#include<iostream>
using namespace std;
class A
{
    public:
        A()
        {
            cout<<"A()\n";
        }
        A(const A & a)
        {
            cout<<"A(const A&)\n";
        }
        A& operator = ( const A & a)
        {
            cout<<"operator =\n";
        }
        A* operator = (const A * a)
        {
            cout<<"operator = *\n";
            return this;
        }

};
 int main()
{
    A aobj;
    A aobj2;
    aobj = aobj2;
    A* ptra;
    ptra = &aobj2;/* this is treated as normal assignment, and operator= * is not called.*/
}
