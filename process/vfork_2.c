#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a = 10;

int main(int argc, char const *argv[])
{
    
    // 使用vfork创建完子进程
    // 在子进程执行exit或者exec之前，父子进程共有一块地址空间
    pid_t pid;
    int b = 9;

    pid = vfork();
    if(pid < 0)
    {
        perror("no");
        exit(1);
    }
    if(pid == 0)//子进程
    {
        a++;
        b++;
        perror("sona%d ,b%d \n",a,b);
        exit(0);
    }
    else //父进程
    {

        printf("father a%d ,b%d \n",a,b);
    }
    return 0;
}
