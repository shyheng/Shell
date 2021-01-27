#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun(void *a)
{
    while (1)
    {
        printf("子线程正在运行\n");
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    
    if(pthread_create(&thread,NULL,thread_fun,NULL) != 0)
    {
        perror("out");
        exit(1);
    }

    //通过调用pthread_cancel函数取消一个子线程
    sleep(3);
    pthread_cancel(thread);
    pthread_join(thread,NULL);
    return 0;
}
