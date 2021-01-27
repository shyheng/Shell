#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun(void *a)
{
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);

    //设置为立即取消
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    // 设置为不立即取消
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);

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
