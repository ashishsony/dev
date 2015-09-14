#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class A
{
    public:
        int x;
        string s;
        A(){cout<<"\nA()\n";}
        A(int xx,string ss):x(xx),s(ss)
    {
        cout<<"A::A()"<<x<<","<<s<<"\n";
    }
        A(const A& that)
        {
            cout<<"cpy ctr\n";
            x=that.x;
            s=that.s;
        }
        A& operator=(const A& that)
        {
            cout<<"operator=\n";
        }
        ~A()
        {
            cout<<"~A()"<<s<<"\n";
        }
};

const A& getA1()
{
     A a(1,"A1");
    cout<<"returning from A1\n";
    return a;
}

A& getA2()
{
    A a(2,"A2");
    cout<<"returning from A2\n";
    return a;
}

A getA3()
{
    A a(3,"A3");
    cout<<"returning from A3\n";
    return a;
}
void assignToRef(A& ref)
{
    cout<<"\nassignToRef\n";
    A abj;
    ref=abj;
}
A passvalue()
{
    cout<<"\npassvalue\n";
    A abj;
    return abj;
}
const string& getA4(const string& a)//returning a const ref to a const ref param is not advisable... as the compiler doesnt destruct the temp "ashish"
    //untill its passing to this fun,so the temp string gets destructed as soon its returned from here. so the reciever is a dangling ref.
    //returning a non-const ref to a const ref param is ok because if a temp is passed to this fun,the compiler reports that as an error,if a temp isnt 
    //passed things are fine because things dont start with a "temporary".check it just make the return type as non const and the compiler will report tht.
{
    cout<<"returning from A4\n";
    return a;
}
int main()
{ 
    A &newA2 = getA2();       //.....................LINE 2// removing & will make it call copy ctr here.. which will fail as referent dies at this point..
    cout<<"returned from A2\n";
    cout<<"-----------------------------\n";
    A newA3 = getA3();       //......................LINE 3
    //A const  newConstA3 = getA3 ();
    cout<<"returned from A3\n";
    cout<<"-----------------------------\n";
    //cout<<"newA2="<<newA2.x<<","<<newA2.s<<"\n";
    cout<<"newA3="<<newA3.x<<","<<newA3.s<<"\n";
    string ash("ashish");
//const string &str= getA4("ashish");
const string &str= getA4(ash);
    cout<<"getA4="<<str<<"\n";
A aobj;
assignToRef(aobj);
A aobj1=passvalue();
}
