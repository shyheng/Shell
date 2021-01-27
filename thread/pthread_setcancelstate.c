#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun(void *a)
{
    //通过pthread_setcancelstate设置取消的状态
    // 设置为可以取消
    // pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
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

    sleep(3);
    pthread_cancel(thread);

    pthread_join(thread,NULL);
    return 0;
}
