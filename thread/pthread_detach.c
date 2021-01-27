#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void *a)
{
    printf("子进程执行\n");
    sleep(3);
    printf("关闭\n");
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    if(pthread_create(&thread,NULL,thread_fun,NULL) != 0)
    {
        perror("out");
        exit(1);
    }
// pthread_detach函数 是分离态，既不用阻塞，也可以自动回收
    if (pthread_detach(thread) != 0)
    {
         perror("out");
         exit(1);
    }
    

//如果原本子线程是一个结合态，需要通过pthread函数回收子线程退出资源
// 但是这个函数是一个阻塞函数，如果不退出，主线不会进行
// 大大的限制了代码的运行效率
// 结合态和分离态互不兼容
#if 0
    if (pthread_join(thread,NULL) != 0)
    {
        perror("out");
        eixt(1);
    }
#endif

    while (1);
    {
        printf("hello");
        sleep(1);
    }
    
    return 0;
}
