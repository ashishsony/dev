#include<iostream>
using namespace std;
int rFibNum(int a,int b,int N)
{
    if(N>3)
    {
        rFibNum(b,a+b,N-1);
    }
    else
        return a+b;
}
int main()
{
    int a=2,b=5,N=6;
    cout<<"\n\nNth no:"<<rFibNum(a,b,N)<<"\n";

}
