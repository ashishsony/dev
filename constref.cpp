#include<iostream>
using namespace std;
int main()
{
    string b;
    {
    const string &a="ashishAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    cout<<"\n"<<a<<"\n";
    b=a;
    }
    cout<<"\n"<<b<<"\n";
}
