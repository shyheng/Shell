#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    int i = 0;
//创建信号集，并在信号集里添加信号
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    while(1)
    {
        //将set信号集添加到信号阻塞集
        sigprocmask(SIG_BLOCK,&set,NULL);
        for(i=0;i<5;i++)
        {
            printf("BLOCK\n");
            sleep(1);
        }

        //将set信号集从信号阻塞集中删除
        sigprocmask(SIG_UNBLOCK,&set,NULL);
        for(i=0;i<5;i++)
        {
            printf("unblock\n");
            sleep(1);
        }
    }
    return 0;
}
