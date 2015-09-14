#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<stdlib.h>

int fd[2];
int iValue = 44;
void open_pipe(void)
{
    /*
     ** Notice here .It is the same as pipe()
     */
  /*  if(socketpair(PF_UNIX,SOCK_STREAM,0,fd) < 0)
    {
        fprintf(stderr,"File : %s , Line : %d , socketpair error:",
                __FILE__,
                __LINE__); 
        perror("");
        abort();
    } 
    */
    pipe(fd);
}

void *do_task(void *arg)
{
    int n;

    printf("\t come into thread \n");
char ch;
while( read(fd[0],&ch,sizeof(char)) > 0)
    printf("\t child1 ,ch = %c\n", ch);

    return (void *) NULL;
}

void main(void)
{
    int iRetSts,i=0;;
    pthread_t iThreadId;
    pthread_attr_t vThreadAttr;

    open_pipe();

    pthread_attr_init(&vThreadAttr);
    pthread_create(&iThreadId,NULL,do_task,(void *)NULL);
    char * msg = "ashish is coming through the pipe!";
        while(msg[i] != '\0')
        {
    iRetSts = write(fd[1],&msg[i],sizeof(char));
    printf("\t parent ,ch = %c\n", msg[i]);
    if(iRetSts == -1)
    {
        fprintf(stderr,"File : %s , Line : %d , write failed \n",
                __FILE__,
                __LINE__);
        perror("");
    } 
    i++;
        }
        close(fd[1]);
    pthread_join(iThreadId,0);
}
