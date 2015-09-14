#include<iostream>
using namespace std;
class Wilma
{
    public:
        static int i;
        static const int j;
        Wilma()
        {
            cout<<"\nWilma ctor\n";
            cout<<"\ni::"<<i<<"\n";
        }
};
class Fred
{
    public:
        Fred()
        {
            cout<<"\nFred ctor\n";

        }
        static Wilma wilma_;
};
int Wilma::i=44;//------------- LINE A
const int Wilma::j=9;
int main()
{
    //int a=0;
    Wilma::i=1;
    const int *a = &Wilma::j;
    //Wilma w;
    Fred::wilma_=Wilma();//---------- LINE B

}
