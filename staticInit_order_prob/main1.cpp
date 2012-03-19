#include<iostream>
using namespace std;
class Wilma 
{
    public:
        static int i;
        int j;
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
            //Wilma::i=-1;
        }
        static Wilma wilma_;
};
//int Wilma::i=44;
int main()
{
    int a=0;
    Wilma::i=a;
    Wilma w;
    Fred::wilma_=w;

}

