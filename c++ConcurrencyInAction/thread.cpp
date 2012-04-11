#include<iostream>
#include<thread>
using namespace std;
void fun()
{
    cout<<"This is called from c++11 thread lib!";
}
int main()
{
    thread th1(fun);
    th1.join();
}
