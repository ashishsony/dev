#include<stdio.h>
#include<stdlib.h>

int main()
{

    int ** DDarray;
    int i=0,j=0;
    int N = 20;
    DDarray = (int**)malloc(sizeof(int*) * N);
    for(;i<N;i++)
    {
        DDarray[i] = (int*)malloc(sizeof(int) * N);
    }
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            DDarray[i][j]=45;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d :",DDarray[i][j]);
        printf("\n");
    }

}
