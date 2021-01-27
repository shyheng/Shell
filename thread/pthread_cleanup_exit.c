#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void mycleanup(void *a)
{
    printf("clean un = %s \n",(char *)a);
    free((char *)a);
}

void *thread(void *a)
{
    
    // 建立线程清理程序
    printf("thread\n");

    char *ptr = NULL;
    ptr = (char*)malloc(100);
    pthread_cleanup_push(mycleanup,(void *)(ptr));
    bzero(ptr,100);
    strcpy(ptr,"malloc");
    
    sleep(3);    
    printf("exit\n");

    pthread_exit(NULL);

    // 注意push与pop必须配对使用，即使pop执行不到
    printf("pop");
    pthread_cleanup_pop(1);
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread,NULL);//创建一个线程
    pthread_join(tid,NULL);
    printf("结束");
    return 0;
}
