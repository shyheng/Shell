#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

//通过信号量实现互斥操作

//第一步：创建一个信号量
sem_t sem;

void printer(char *str)
{
    // 第三步，执行p操作
    //由于使用信号量实现互斥，信号量的初始值为1，则两个线程执行p操作
    // 先执行p操作的线程继续执行，后执行p操作的先阻塞
    sem_wait(&sem);
    while (*str)
    {
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    //第四步：执行v操作
    sem_post(&sem);
}

void *thread_fun1(void *arg)
{
    char *str1 = "hello";
    printer(str1);
}
void *thread_fun2(void *arg)
{
    char *str2 = "world";
    printer(str2);
}

int main(int argc, char const *argv[])
{
    //第二步：初始化
    sem_init(&sem,0,1);
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,thread_fun1,NULL);
    pthread_create(&tid2,NULL,thread_fun2,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("\n");
    //第五步：使用完销毁
    sem_destroy(&sem);
    return 0;
}
