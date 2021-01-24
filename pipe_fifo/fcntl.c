#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd_pipe[2];
    char buf[] = "hello";
    pid_t pid;

    if(pipe(fd_pipe) < 0)
    {
        perror("sshy");
        exit(1);
    }

    pid = fork();
    if (pid < 0)
    {
        perror("out");
        exit(1);
    }
    if (pid == 0)
    {
        while (1)
        {
            sleep(5);
            write(fd_pipe[1],buf,strlen(buf));
        }
    }
    else
    {
        //将fd_pipe[0]设置为阻塞
        fcntl(fd_pipe[0],F_SETFL,0);
        //将fd_pipe[0]设置为非阻塞
        // fcntl(fd_pipe[0],F_SETFL,O_NONBLOCK);
        while (1)
        {
            memset(buf,0,sizeof(buf));
            read(fd_pipe[0],buf,sizeof(buf));
            printf("buf=%s",buf);
            sleep(1);
        }
    }
    return 0;
}
