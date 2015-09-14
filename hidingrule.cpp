#include<iostream>
using namespace std;
class B
{
    public:
        B& operator=(const B& that)
        {
            cout<<"\nB& operator=(const B& that)\n";
        }
        virtual void fun(B& b)
        {
            cout<<"\nB::fun()\n";
        }
};
class D2;
class D1:public B
{
    public:
        //if we dont provide an assignment operator the compiler generates one D1& D1::operator=(const D1&) ,so the assignment operator from 
        //base B gets hidden atomatically due to hiding rule!


        //D1& operator=(const D2& that)
        B& operator=(const B& that)
        {
            cout<<"\nD1& operator=(const D1& that)\n";
        }/**/
        //void fun(D1& d1)
        void fun(B& b)
        {
            cout<<"\nD1::fun()\n";
        }
};
class D2:public B
{
    public:
        D2& operator=(const D2& that)
        {
            cout<<"\nD2& operator=(const D2& that)\n";
        }
        void fun(B& b)
        //void fun(D2& d2)
        {
            cout<<"\nD2::fun()\n";
        }
};
int main()
{
    D1 d1;
    D2 d2;
    B b1,b2;
    b1=b2;
    d1=d2;
//    B& bp=d1;
  //  bp.fun(d2);

}
