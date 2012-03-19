#include <iostream>
using namespace std;
class Base {
    public:
        virtual ~Base()
            throw();
        virtual void f(float x) throw();
        virtual void g(float x) throw();
        virtual void h(float x) throw();
};
Base::~Base() throw()
{ }
void Base::f(float x) throw()
{ cout << "Base::f(float)\n"; }
void Base::g(float x) throw()
{ cout << "Base::g(float)\n"; }
void Base::h(float x) throw()
{ cout << "Base::h(float)\n"; }
class Derived : public Base {
    public:
        virtual void f(float x) throw();
        virtual void g(int x)   throw();
        virtual void h()       throw();
        //using Base::g;
        using Base::h;
};
// Normally this would hide g(float) (bad!)
// but this line un-hides g(float) (good!)
void Derived::f(float x) throw()
{ cout << "Derived::f(float)\n"; }
void Derived::g(int x) throw()
{ cout << "Derived::g(int)\n"; }
void Derived::h() throw()
{ cout << "Derived::h()\n"; }
void sample(Base& b, Derived& d)
{
    b.f(3.14f);
    d.f(3.14f);
    b.g(3);
    d.g(3);    // This is not hidden (good!)
    d.g(3.14f);    // This is not hidden (good!)
    b.h(3.14f);
    d.h(3.14f);
    d.h();
}
int main()
{
    Derived d;
    sample(d, d);
}

