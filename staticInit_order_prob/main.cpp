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
            Wilma::i=-1;
        }
        static Wilma wilma_;
};
class Fred2
{
    public:
        Fred2()
        {
            Wilma w;
            Fred::wilma_=w;
        }
        static Fred fred_;
};
Fred Fred_;
Fred2 Fred2_;
//Wilma Fred::wilma_;
int Wilma::i=44;
int main()
{
    cout<<"\nMain()\n";
    Wilma w;
    Fred::wilma_=w;
    //Fred::wilma_.f();

}

