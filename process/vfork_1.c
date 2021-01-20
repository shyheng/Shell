#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    
    pid_t pid;

//使用vfork函数创建完子进程后
// 子进程会执行，直到子进程执行exit或者exec后，父进程才会执行
    pid = vfork();
    if(pid < 0)
    {
        perror("no");
        exit(0);
    }
    if(pid == 0)//子进程
    {
        int i = 0;
        for(i=0;i<5;i++)
        {
            printf("son\n");
            sleep(1);
        }
        exit(0);
    }
    else //父进程
    {
        while (1)
        {
            printf("father\n");
            sleep(1);
        }
        
    }
    return 0;
}
