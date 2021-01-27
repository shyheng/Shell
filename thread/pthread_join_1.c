#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void *arg)
{
    printf("子线程执行\n");

    sleep(3);

    printf("子线程要退出了\n");
}

int main(int argc, char const *argv[])
{
    printf("主线程执行");

    pthread_t thread;

    if(pthread_create(&thread,NULL,thread_fun,NULL) != 0)
    {
        perror("out");
        exit(1);
    }

    //通过调用pthread_join函数阻塞等待子线程退出
    if (pthread_join(thread,NULL) != 0)
    {
        perror("out");
        exit(1);
    }
    

    printf("进程要退出\n");

    return 0;
}
