#include <iostream>
using namespace std;
class Fred {
    public:
        friend void operator>> (istream& istr, Fred& x) throw();
        friend void operator<< (ostream& ostr, Fred x) throw();
    protected:
        int i_;
};
void operator>> (istream& istr, Fred& x) throw()
{
    istr >> x.i_;
    //return istr;
}
void operator<< (ostream& ostr, Fred x) throw()//should return ostream& for concatenation of << operator

{
    ostr<<x.i_;
    //return ostr;
}
int main()
{
    Fred f;
    cin>>f;
    cout<<"as"<<f;
    //cout<<"as"<<f<<"ashish"; try uncomenting this

}
