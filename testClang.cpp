#include <iostream>
#include <boost/thread.hpp>

#define len 1000000000L

static void f(unsigned long a, unsigned long b, unsigned long *va)
{
        for (*va = 0; a < b; a++)
                    *va += a;
}
    
int main()
{
        unsigned long va = 0;
            boost::thread a(f, 0l,  2* len, &va);
                a.join();
                    std::cout << va  << std::endl;
                        return 0;
}
