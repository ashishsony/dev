#include<iostream>
#include<typeinfo>
using namespace std;
class Ashish
{
};
int main()
{
    Ashish *a;
    cout<<"\n"<<typeid(a).name()<<"\n";
    //type_info t=    typeid(a);

}
