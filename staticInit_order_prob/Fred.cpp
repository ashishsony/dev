#include"Fred.hpp"
//#include"Wilma.hpp"
#include"iostream"
using namespace std;
Fred::Fred()
    {
        cout<<"\nFred Ctor\n";
        Wilma::f();
        Wilma t;
        wilma_=t;
    }

