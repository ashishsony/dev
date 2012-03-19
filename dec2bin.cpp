#include<iostream>
#include<vector>
using namespace std;
vector<short> out;
short dec2bin(unsigned int num)
{
    short b=num%2;
    num=num/2;
    if(num>0)
        out.push_back(dec2bin(num));
    return b;

}
int main()
{
        cout<<"\n";
        unsigned int a=~0;
        cout<<"\na="<<a<<endl;
        out.push_back(dec2bin(a));
    for(int i=0;i<out.size();i++)
        cout<<out[i];
    return 0;
}
