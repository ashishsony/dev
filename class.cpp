#include<iostream>
using namespace std;
class A
{
    public:
        virtual void a();
        virtual ~A();
};
void A::a()
{
    cout<<"A::a()\n";
}
//A::~A()
//{}
class B:public A
{
    public:
        //void a();
};
//void B::a()
//{
  //  cout<<"B::a()\n";
//}
int main()
{
    A aobj;
    B bobj;
    //aobj.a();
    //bobj.A::a();
    //bobj.a();
    A* pa=new B();
    A* pa1=new A();
    A& aref=*pa1;
    //B* pb;
    //try
    //{
        B& pb=dynamic_cast<B&>(aref);
    //}
    //catch()
    {
      //  cout<<"Exception\n";
    }
    pa->a();
    pb.a();

}
