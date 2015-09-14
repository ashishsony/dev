#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string
using namespace std;

int main () {
    std::string foo = "foo-string";
    std::string *bar = new std::string("bar-string");
    cout<<"*bar,bar before moving:"<<*bar<<","<<bar<<endl;
    std::vector<std::string> myvector;

    myvector.push_back (foo);                    // copies
    myvector.push_back (std::move(*bar));         // moves

    std::cout << "myvector contains:";
    for (std::string& x:myvector) std::cout << ' ' << x;
    std::cout << '\n';
    std::cout << "bar is now:"<<bar<<"\n and *bar:"<<*bar<<"size:"<<bar->size()<<endl;;
    int *abc = new int(-40);
    int sf =40;;
    //abc=&sf;
    //sf = *abc;
    //const int &z = sf;
    int &z = sf;
    z = *abc;

    return 0;
}
