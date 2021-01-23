#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include  <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

void handler(int sig)
{
    printf("SIGINT\n");
}

int main(int argc, char const *argv[])
{
    signal(SIGINT,handler);
    //案例1 
#if 0 
//sleep是一个可重入函数 但是当执行信号处理函数之后，不会回到原来的位置继承睡眠
    // sleep(10);
//alarm函数是一个可重入函数 当执行时 如果有信号产生并执行信号处理函数 执行完毕会继续执行
    alarm(10);

    while (1)
    {
        printf("shy\n");
        sleep(1);
    }
#endif

#if 1
    char buf[32] = "";

//read也是一个可重入函数，在等待终端输入是，如果产生信号并执行信号处理函数，信号
// 函数执行完毕后 可以进行输入数据 read可以读取到信号处理信号函数之后
    if (read(0,buf,20) == -1)
    {
        perror("no");
        exit(1);        
    }
    printf("shy%s",buf);
#endif
    return 0;
}
