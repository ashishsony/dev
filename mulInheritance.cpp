#include<iostream>
using namespace std;
class B
{
    int priv;
    public:
    int pub;
};
class D1:private virtual B
{

};
class D2:public virtual B
{
};
class D3:public D1,public D2
{
    public:
        void fun()
        {
            //priv=2;
        }
};
int main()
{
    D3 d3;
    d3.pub=1;
    d3.fun();
}
