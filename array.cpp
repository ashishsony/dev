#include<iostream>
using namespace std;
class A
{
    public:
        A()
        {
            a=0;
        }
        A(int a)
        {
            a=a;
        }
        int a;
};
void fun()
{
    cout<<"ashish\n";
};
int main()
{
    fun();
    A aarray[10];//=A(1);
    for (int i=0;i<10;i++ )
        cout<<"i"<<i<<"[]"<<aarray[i].a<<endl;
}
