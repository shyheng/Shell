#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork(); 
    if(pid < 0)
    {
        perror("out");
        exit(1);
    }
    else if(pid > 0)//父进程的代码
    {
        while (1)
        {
            printf("father\n");

            sleep(1);
        }
        
    }
    else //子进程代码
    {
        printf("son\n");

        //子进程在3秒之后让父进程退出
        sleep(3);

        //使用kill函数给父进程发送信号 然后父进程直接退出
        kill(getppid(),SIGINT);
    }
    return 0;
}
