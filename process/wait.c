#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
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
            printf("son\n");
            sleep(1);
        }

        // 使用exit退出当前进程并设置退出状态
        exit(2);
    }
    else 
    {
        //使用wait在父进程中阻塞等待子进程的退出
        // 不接收子进程的退出状态
        // wait(NULL);

        //接受子进程的退出状态，子进程中必须使用exit或者_exit发送退出状态

        int status= 0;
        wait(&status);

        if(WIFEXITED(status) != 0)
        {
            printf("son%d\n",WEXITSTATUS(status));
        }

        printf("fa\n");
    }
    return 0;
}


