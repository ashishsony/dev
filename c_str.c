//#include<iostream>
#include<stdio.h>
int main()
{
char *c = "abc";
*c = 'd';
printf("%s",c);
return 0;
}