#include<iostream>
using namespace std;
bool isLeap(int year)
{
    if(  (year%4==0 && year%100!=0)  ||  (year%4==0 && year%100==0 && year%400==0) )
        return true;
    else 
        return false;
}
int main()
{
    int start,end,totalLeaps=0;
    cout<<"Enter starting year:";
    cin>>start;
    cout<<"Enter Ending year:";
    cin>>end;
    for(int i=start;i<end;++i)
    {
        if(isLeap(i))
        {
            totalLeaps++;
        }
    }
    int remainder=(totalLeaps+end-start)%7;
    switch(remainder)
    {
        case 0:
            cout<<"First Day Will be:Monday";
            break;
        case 1:
            cout<<"First Day Will be:Tuesday";
            break;
        case 2:
            cout<<"First Day Will be:Wednesday";
            break;
        case 3:
            cout<<"First Day Will be:Thursday";
            break;
        case 4:
            cout<<"First Day Will be:Friday";
            break;
        case 5:
            cout<<"First Day Will be:Saturday";
            break;
        case 6:
            cout<<"First Day Will be:Sunday";
            break;
    }
}
