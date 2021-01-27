#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//一个进程中的多个线程执行顺序不确定
// 多线程执行时跟进程一样，是来回切换运行，跟调度机制一样

void *pthread_fun1(void *arg)
{
    printf("子线程1执行");
    sleep(1);
    printf("*****************");
}

void *pthread_fun2(void *arg)
{
    printf("子线程2执行");
    sleep(1);
    printf("*****************");
}

int main(int argc, char const *argv[])
{
    pthread_t thread1, thread2;
    
    if (pthread_create(&thread1,NULL,pthread_fun1,NULL) != 0)
    {
        perror("out");
        exit(1)
    }
    
    if (pthread_create(&thread2,NULL,pthread_fun2,NULL) != 0)
    {
        perror("out");
        exit(1)
    }

    while(1);
    return 0;
}
