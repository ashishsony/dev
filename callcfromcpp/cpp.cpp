// This is C++ code
#include<iostream>
using namespace std;
extern "C" {
    void sample(int i, char c, float x) throw();
}
void sample(int i, char c, float x) throw()
{
    // The C++ code that defines the function goes here
    cout<<"\nThis is a c++ function!\n";
    cout<<"\ni,c,x="<<i<<","<<c<<","<<x<<"\n";
}

