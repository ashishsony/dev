#include <stdio.h>
#include <pthread.h>

static volatile int balance = 0;

void *deposit(void *param)
{
    char *who = param;

    int i;
    printf("%s: begin\n", who);
    for (i = 0; i < 1000000; i++) {
        balance = balance + 1;
    }
    printf("%s: done\n", who);
    return NULL;
}

int main()
{
    pthread_t p1, p2;
    printf("main() starts depositing, balance = %d\n", balance);
    pthread_create(&p1, NULL, deposit, "A");
    pthread_create(&p2, NULL, deposit, "B");

    // join waits for the threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("main() A and B finished, balance = %d\n", balance);
    return 0;
}

