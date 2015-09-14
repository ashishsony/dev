#include<stdio.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
sem_t semaphore;
pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;
void *writePipe(void* f)
{
    //printf("f:%s, l:%d",__func__,__LINE__);
    int *fd = (int*)f;
    char * msg = "Ashish through pipe!";
    int i=0;
    //close(fd[0]);
    printf("\nchild:\n");
    while(msg[i] !='\0')
    {
        pthread_mutex_lock(&mutex);
        //sem_wait(&semaphore);
        while(count % 2 != 0)
        {
        pthread_cond_wait(&cond,&mutex);
        }
        count ++;
        write(fd[1],&msg[i],sizeof(char));
        printf("@:%c\n",msg[i]);
        i++;
        //sem_post(&semaphore);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

    }
    close(fd[1]);
}
void *readPipe(void* f)
{
    int *fd = (int*)f;
    char ch;
    //close(fd[1]);
    printf("\nParent\n");
    int once = 1;
    while (read(fd[0],&ch,sizeof(char)) > 0)
    {
        //sem_wait(&semaphore);
        pthread_mutex_lock(&mutex);
        while(count % 2 == 0)
        {
        pthread_cond_wait(&cond,&mutex);
        }
        count++;
        //pthread_mutex_lock(&mutex);
        printf("#:%c\n",ch);
        //sem_post(&semaphore);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
    }
}
int main()
{
    pthread_mutex_init(&mutex,0);
    pthread_cond_init(&cond,0);
    sem_init(&semaphore,0,1);
    int fd[2];
    pid_t childpid;
    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);

    }
    char * msg = "Ashish through pipe!";
    char  buf[80];
    pthread_t pipeIn,pipeOut;
    pthread_create(&pipeIn,0,&writePipe,fd);
    pthread_create(&pipeOut,0,&readPipe,fd);
    pthread_join(pipeIn,0);
    pthread_join(pipeOut,0);
}
