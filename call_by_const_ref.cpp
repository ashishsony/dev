#include<iostream>
using namespace std;
class A
{
    public:
        void fun1(const A& );
        void print() const ;
        void print1()const  ;
    private:
        int a_;
};

void A::print1()const 
{
    cout<<a_<<"\n";
}
void A::print() const
{
    cout<<a_<<"\n";
}

void fun(const A& t)
{
    t.print();
}

void A::fun1(const A& t)
{
    t.print1();
}
int main()
{
    const A obj;
    fun(obj);
}
