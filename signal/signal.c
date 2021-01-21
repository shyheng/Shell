#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig);

int main(int argc, char const *argv[])
{
    //以默认的方式处理信号
#if 0
    if(signal(SIGINT,SIG_DFL) == SIG_ERR)
    {
        perror("mr");
        exit(1);
    }
    if (signal(SIGQUIT,SIG_DFL) == SIG_ERR)
    {
        perror("mr");
        exit(1);
    }
    
#endif

//以忽略的方式来处理
#if 0
    if (signal(SIGINT,SIG_IGN) == SIG_ERR)
    {
        perror("hl");
        exit(1);
    }
    if (signal(SIGQUIT,SIG_IGN) == SIG_ERR)
    {
        perror("hl");
        exit(1);
    }
    if (signal(SIGTSTP,SIG_IGN) == SIG_ERR)
    {
        perror("hl");
        exit(1);
    }
    //SIGKILL和SIGSTOP只能以默认方式处理，不能忽视和捕捉
    if (signal(SIGKILL,SIG_IGN) == SIG_ERR)
    {
        perror("hl");
        exit(1);
    }
#endif

 // 以自定义方式处理信号
#if 1
    if (signal(SIGINT,handler) == SIG_ERR)
    {
        perror("zdy");
        exit(1);
    }
    if (signal(SIGQUIT,handler) == SIG_ERR)
    {
        perror("zdy");
        exit(1);
    }
    if (signal(SIGTSTP,handler) == SIG_ERR)
    {
        perror("zdy");
        exit(1);
    }
#endif

    while (1)
    {
        printf("shy\n");
        sleep(1);
    }
    
    return 0;
}

void handler(int sig)
{
    if(sig == SIGINT)
    {
        printf("SIGINT正在处理\n");
    }
    if(sig == SIGQUIT)
    {
         printf("SIGQUIT正在处理\n");
    }
    if(sig == SIGTSTP)
    {
         printf("SIGTSTP正在处理\n");
    }
}