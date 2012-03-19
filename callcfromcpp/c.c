/* This is C code */
#include<stdio.h>
void sample(int i, char c, float x) throw();
void myCfunction()
{
    // ...
    printf("This is a c function! calling sample() c fun\n");
    sample(42, 'a', 3.14);
    // ...
}

