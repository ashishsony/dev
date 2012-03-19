#include<iostream>
using namespace std;
class B
{
    public:
    ~B()
    {
        cout<<"~B()\n";
    }
};
class D:public B
{
    public:
    static D createD()
    {
        return D();
    }
    ~D()
    {
        cout<<"~D()\n";
    }
};
int main()
{
    {
        B *bobj=new D();
        delete bobj;
        const B &b=D::createD();
    }
}
