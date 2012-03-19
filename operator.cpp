#include<iostream>
using namespace std;
class A
{
    int a;
    //friend istream& operator>>(istream&,A&);
    friend void operator>>(istream&,A&);
    friend void operator<<(ostream&,const A&);
};
//istream& operator>>(istream& istr ,A& obj)
void operator>>(istream& istr ,A& obj)
{
    istr>>obj.a;
    cout<<"\nrecieved:"<<obj.a<<" from stream.\n";
    //return istr;
}
void operator<<(ostream& ostr ,const A& obj)
{
    ostr<<obj.a;
}
int main()
{
    A o;
    cin>>o;
    cout<<o;
}
