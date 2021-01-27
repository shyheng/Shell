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
        //设置取消点，接受到取消信号，进行取消
        pthread_testcancel();
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
