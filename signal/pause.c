#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("out");
        exit(1);
    }
    else if(pid > 0)//父进程
    {
        printf("father");

        // 阻塞等待进程信号
        pause();
    }
    else//子进程
    {
        printf("son");

        sleep(3);

        kill(getppid(),SIGINT);
    }
    return 0;
}
