/*
 
http://www.phpcompiler.org/articles/virtualinheritance.html
 */
#include<iostream>
#include <stdio.h>
using namespace std;
class B
{
    int priv;
    public:
    int pub;
    void fun1()
    {
    }
};
class D1:public B
{

};
class D2:public B
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
    //D3 d3;
    D3* d3 = new D3;
    D1 * d1 = new D1;
    B* b1 = (D1*)d3;;
    B* b2 = (D2*)d3;;/* this typecasting will find the place for d2 in d3's memory layout, and assign the proper address to b2! 
                        so typecasting does some real work when required and is not trivial at all times.*/
    printf("b1:%p b2:%p",b1,b2);
    B* b3 = (D2*)new D3;
    //B* b4 = new D3;//error
    //d3.pub=1;
 //   d3.fun();
}
