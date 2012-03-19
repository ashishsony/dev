
#include<iostream>
#include<string>
using namespace std;
    string trim="wweellccoommee to code  jam";
    string chk="welcome to code jam";
int noOfChars(int l,int u,char c)
{
    cout<<"c:\""<<c<<"\",";
    int a=1;
    for(int i=l+1;i<u;++i)
    {
        if(trim[i]==c)
        {
            cout<<"t:\""<<trim[i]<<"\",";
            a++;
        }
        else
            cout<<"t*:\""<<trim[i]<<"\",";
    }

    return a;
}
int main()
{
    int ar[]={0,2,4,6,8,10,12,14,15,16,17,18,19,20,21,22,24,25,26};
    int arno[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        for(int i=0;i<chk.size()-1;++i)
        {
            arno[i]=noOfChars(ar[i],ar[i+1],chk[i]);
        }
            cout<<"\narno[]=";
        for(int i=0;i<chk.size();++i)
            cout<<arno[i]<<",";
}
