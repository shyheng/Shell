#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        perror("no");
        return -1;
    }
    else if(pid == 0)
    {
        int i = 0;
        for(i=0;i<5;i++)
        {
            printf("is good son\n");
            sleep(1);
        }
        exit(0);
    }
    else 
    {
        waitpid(pid,NULL,0);
        printf("father ok");
    }
    return 0;
}
