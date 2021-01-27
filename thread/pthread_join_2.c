#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void *arg)
{
    static int num = 666;
    printf("子线程执行\n");

    sleep(3);

    printf("子线程要退出了\n");

    //子线程如果要返回退出状态，可以通过返回值或者通过pthread_exit函数
    return (void *)&num;
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

    int *num;
    if (pthread_join(thread,(void **)&num) != 0)
    {
        perror("out");
        exit(1);
    }
    
    printf("val = %d\n",*num);
    printf("进程要退出\n");

    return 0;
}
