#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //通过fork函数创建一个子进程,
#if 0
    // 在原来的基础上创建一个新的子进程
    // 如果 fork之后不分父子进程的代码取则后面代码都会执行
    //不建议
    fork();
    printf("shy\n");
    while (1);
#endif

// 通过fork函数的赋值来区分父子进程的独立代码区
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        perror("no");
        return -1;
    }
    else if(pid > 0)//父进程的代码区
    {
        while (1)
        {
            printf("pid=%d,ppid=%d\n",getpid(),getppid());
            printf("你爹\n");
            sleep(1);
            printf("###########");
        }
        
    }
    else //子进程代码区
    {
        while (1)
        {
            printf("pid=%d,ppid=%d\n",getpid(),getppid());
            printf("son\n");
            sleep(1);
            printf("________________");
        }
    }

    return 0;
}
