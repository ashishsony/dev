#include<iostream>
#include<thread>
using namespace std;
void fun()
{
    cout<<"This is called from c++11 thread lib!";
}
int main()
{
    {
        thread th1(fun);
        thread &a=th1;
    }
    cout<<"\njjjjjjjjjjj\n";
    a.join();
}
