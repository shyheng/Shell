#include <signal.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    //创建一个信号集
    sigset_t set;
    int ret = 0;

    //初始化一个空的信号集
    sigemptyset(&set);

    //判断SIGINT信号是否在信号集中
    ret = sigismember(&set,SIGINT);
    if (ret == 0)
    {
        printf("shy\n%d",ret);
    }

    //将指定信号添加到信号集中
    sigaddset(&set,SIGINT);
    sigaddset(&set,SIGQUIT);

    ret = sigismember(&set,SIGINT);
    if (ret == 1)
    {
        printf("== 1\n%d",ret);
    }
    
    
    return 0;
}
