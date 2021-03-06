#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void mycleanup1(void *a)
{
    printf("1");
    printf("clean un = %s \n",(char *)a);
    free((char *)a);
}

void mycleanup2(void *a)
{
    printf("1");
}
void *thread(void *a)
{
    
    // 建立线程清理程序
    printf("thread\n");
    char *ptr = NULL;
    ptr = (char*)malloc(100);
    pthread_cleanup_push(mycleanup1,(void *)(ptr));
    pthread_cleanup_push(mycleanup2,NULL);
    bzero(ptr,100);
    strcpy(ptr,"malloc");
    // 注意push与pop必须配对使用，即使pop执行不到
    printf("pop");
    pthread_cleanup_pop(1);
    printf("pop");
    pthread_cleanup_pop(1);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread,NULL);//创建一个线程
    sleep(5);
    printf("cencel\n");
    pthread_cancel(tid);
    pthread_join(tid,NULL);
    printf("结束\n");
    return 0;
}