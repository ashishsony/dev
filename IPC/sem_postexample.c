#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaphore;

void threadfunc() {
    while (1) {
        sem_wait(&semaphore);
        printf("Hello from da thread!\n");
        sem_post(&semaphore);
        //usleep(2000);
    }
}

int main(void) {
    
    // initialize semaphore, only to be used with threads in this process, set value to 1
    sem_init(&semaphore, 0, 1);
    
    pthread_t *mythread;
    
    mythread = (pthread_t *)malloc(sizeof(*mythread));
    
    // start the thread
    printf("Starting thread, semaphore is unlocked.\n");
    pthread_create(mythread, NULL, (void*)threadfunc, NULL);
    
    getchar();
    
    while(1)
    {
    sem_wait(&semaphore);
    //printf("Semaphore locked.\n");
    
    // do stuff with whatever is shared between threads
        printf("Hello from da main thread!\n");
    
    //printf("Semaphore unlocked.\n");
    sem_post(&semaphore);
        //usleep(2000);
    }
    
    getchar();
    
    return 0;
}
