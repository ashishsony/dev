#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
    string trim="";
    int power(int n,int i)
{
    if(i>0)
    return n*power(n,i-1);
    else
        return 1;
}
int noOfChars(int l,int u,char c)
{
    //cout<<"c:\""<<c<<"\",";
    int a=1;
    for(int i=l+1;i<u;++i)
    {
        if(trim[i]==c)
        {
            //cout<<"t:\""<<trim[i]<<"\",";
            a++;
        }
        //else
            //cout<<"t*:\""<<trim[i]<<"\",";
    }

    return a;
}
int test(string S,int ii)
{
    string chk="welcome to code jam";
        for(int j=0;j<S.size();++j)
        {
            for(int i=0;i<chk.size();++i)
            {
                if(S[j]==chk[i])
                {
                    trim+=S[j];
                    break;
                }
            }
        }
        //cout<<"\nTRimmed:"<<trim<<"\n";
        int *ar=new int[chk.size()];
        int *arno=new int[chk.size()];
        for(int i=0;i<chk.size();++i)
            arno[i]=1;
        for(int i=0,j=0;i<trim.size();++i)
        {
//            for(int j=0;j<trim.size();++j)
            {
                if(trim[i]==chk[j]  )
                {
                    ar[j]=i;
                    j++;
                    //break;
                }
            }
        }
        int trailingM=0;
        for(int i=trim.size()-1;i>0;--i)
            if(trim[i]=='m')
                trailingM++;
            else
                break;
            //cout<<"\nar[]=";
        //for(int i=0;i<chk.size();++i)
          //  cout<<ar[i]<<",";
        //cout<<"\n";
//        int aree[50]={0,2,4,6,8,10,12,14,15,16,17,18,19,20,21,22,23,24,25,26};
        for(int i=0;i<chk.size()-1;++i)
        {
            arno[i]=noOfChars(ar[i],ar[i+1],chk[i]);
        }
            //cout<<"\narno[]=";
     //   for(int i=0;i<chk.size();++i)
       //     cout<<arno[i]<<",";
   //     cout<<"trailingM"<<trailingM;
        int output=1;
        
        for(int i=0;i<chk.size();++i)
            output*=arno[i];
     //   cout<<"power="<<power(2,trailingM-1);
        if(trailingM>0)
            output*=power(2,trailingM-1);

        
        
        int f=1;
        for(int i=0;i<chk.size();i++)
        {
            if(chk[i]==trim[ar[i]])
                f=1;
            else
            {
                f=0;
                break;
            }
        }
/*        if(output==1 && f==1)
        cout<<"Output::"<<output<<"\n";
        else*/
//        cout<<"Case #"<<ii<<": "<<output<<"\n";
        printf("Case #%d: %04d\n", ii, output);
}
char buf[1<<20];
int main()
{
    string s="wwwlelcocmeme otoo  codde jjam";
    freopen("input1.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    gets(buf);
    int a=atoi(buf);
    //cin>> a;
    for(int i=0;i<a;i++)
    {
        gets(buf);
        s=buf;
        //cout<<"orig:"<<s<<endl;
    test(s,i+1);
    trim="";
    }
    /**/
//    test("wweellccoommee to code qps jam");

    
}
