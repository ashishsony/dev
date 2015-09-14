#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int fd[2];
    pid_t childpid;
    if(pipe(fd) < 0)
    {
        perror("pipe");
        exit(1);

    }
    char * msg = "Ashish through pipe!";
    char  buf[80];
    if((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    if(childpid == 0) /*child process*/
    {
        int i=0;
        close(fd[0]);
        printf("\nchild:\n");
        while(msg[i] !='\0')
        {
            usleep(1000);
        write(fd[1],&msg[i],sizeof(char));
        printf("c:%c",msg[i]);
        i++;
        }
        //printf("\nwritten msg from child process: pid:%d\n",(int)getpid());
        exit(0);
    }
    else// parent process
    {
        char ch;
        close(fd[1]);
        printf("\nParent\n");
        int once = 1;
        while (read(fd[0],&ch,sizeof(char)) > 0)
        {
            if (once)
            {
                sleep(1);
                once++;
            }
            printf("p:%c",ch);
        }
        //sleep(5);
        //printf("\nrecieving msg from child process: pid:%d\n",(int)getpid());
        //printf("msg from pipe:%s\n",buf);
        exit(0);
    }
}
