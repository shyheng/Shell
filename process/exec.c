#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    if(pid = fork() < 0)
    {
        perror("no");
        exit(1);
    }
    else if(pid > 0)//父进程
    {
        printf("die\n");
        wait(NULL);
        printf("shy\n")
    }
    else //子进程
    {
        printf("son\n");

#if 0
//不带p命令一定要绝对路径
        if (execl("/bin/ls","ls","-l",NULL) == -1)
        {
            perror("out");
            exit(1);
        }
        
#endif 

#if 0
// 带p的函数，第一个参数即可是相对路径，也可是绝对路径
        if(execlp("ls","ls","-l",NULL) == -1)
        {
            perror("out");
            exit(1);
        }
#endif

#if 0
//带v的函数需要用指针数组来传递
        char *str[] = {"ls","-l",NULL};
        if (execv("/bin/ls",str) == -1)
        {
            perror("out\n");
            exit(1);
        }
        
#endif

#if 0
//exec函数调用可执行文件
        if (execlp("./hello","./hello",NULL) == -1)
        {
            perror("out");
            exit(1);
        }
#endif

#if 0
//exec函数调用可执行文件 不带p也可以
        if (execl("./hello","./hello",NULL) == -1)
        {
            perror("out");
            exit(1);
        }
#endif

#if 1
//exec执行shell脚本
        if (execlp("./myshell.sh","./myshell.sh",NULL) == -1)
        {
            perror("out");
            exit(1);
        }
        
#endif
        // 当exec函数执行完毕后，当前进程结束了
        printf("over");
    }
    return 0;
}
