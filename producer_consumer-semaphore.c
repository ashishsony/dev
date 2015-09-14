#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define MAX 1

int buffer[MAX];
int fill = 0;
int use  = 0;

void put(int value) {
    buffer[fill] = value;     
    fill = (fill + 1) % MAX;  
}

int get() {
    int b = buffer[use];    
    use = (use + 1) % MAX;    
    return b;
}

int loops = 0;

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        int b = get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("%d\n", b);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2 ){
        printf("Needs 2nd arg for loop count variable.\n");
        return 1;
    }

    loops = atoi(argv[1]);

    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
    sem_init(&full, 0, 0);    // ... and 0 are full
    sem_init(&mutex,0,1);

    pthread_t pThread1, pThread2, cThread1,cThread2;
    pthread_create(&pThread1, 0, producer, 0);
    pthread_create(&pThread2, 0, producer, 0);
    pthread_create(&cThread1, 0, consumer, 0);
    pthread_create(&cThread2, 0, consumer, 0);
    pthread_join(pThread1, NULL);
    pthread_join(pThread2, NULL);
    pthread_join(cThread1, NULL);
    pthread_join(cThread2, NULL);
    return 0;
}
