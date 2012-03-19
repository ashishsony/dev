#include<iostream>
using namespace std;
int rBin2Dec(int n)
{
    if(n>0)
    {
        rBin2Dec(n/2);
        cout<<n%2;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"\nEnter a Decimal No:";
    cin>>n;
    cout<<"\n";
    rBin2Dec(n);
}
