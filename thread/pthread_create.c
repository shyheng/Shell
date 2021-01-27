#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//由于线程库不是系统本身的，所以在连接时需要手动连接库源文件
// gcc *.c -lpthread

void *thread_fun(void *arg)
{
    printf("子线程");
}

int main(int argc, char const *argv[])
{
    printf("主线程执行\n");

    pthread_t thread;

    //通过pthread_create函数创建子线程
    if (pthread_create(&thread,NULL,thread_fun,NULL) != 0)
    {
        perror("out");
        exit(1);
    }
    //由于进程结束后，进程中所有的线程都会强制退出，所有不要让进程退出
    while(1);
    return 0;
}
