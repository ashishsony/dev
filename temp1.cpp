#include<iostream>
using namespace std;
class Wilma
{
    public:
        static int i;
        Wilma()
        {
            cout<<"\nWilma ctor\n";
            cout<<"\ni::\n<<i";
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
int main()
{
    int a=0;
    Wilma::i=a;//---------- LINE C
    Wilma w;
    Fred::wilma_=w;//---------- LINE B

}
