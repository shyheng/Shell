#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a =666;

int main(int argc, char const *argv[])
{
    pid_t pid;
    static int b =77;
    int c = 88;

    //子进程会父进程fork之前的所有内容
    //但是fork之后，父子进程完全独立，所有怎么改变（堆区，栈区，数据区）都不会影响
    
    pid = fork();
    if(pid < 0)
    {
        perror("no");
        return -1;
    }
    else if(pid > 0)//父进程的代码区
    {
        printf("die");
        a++;
        b++;
        c++;
        printf("a%d,b%d,c%d",a,b,c);
    }
    else //子进程代码区
    {
        sleep(1);
        printf("son\n");
        printf("a%d,b%d,c%d",a,b,c);
    }

    while (1)
    {
        
    }
    
    return 0;
}
