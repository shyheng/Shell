#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

//使用信号量实现同步功能，如果两个线程实现同步，需要通过两信号量

//第一步：创建两个信号
sem_t sem_g,sem_p;

char ch = 'a';

void *pthread_g(void *arg)
{
    while (1)
    {
        //第四步 后执行的线程中，将信号量初始值为0的信号执行p操作
        sem_wait(&sem_g);

        ch++;
        sleep(1);

        //第六步 后执行 将信号量初始值为1的执行v操作
        sem_post(&sem_p);
    }
}
void *pthread_p(void *arg)//打印ch的值
{
    while (1)
    {
        //第三步，先执行的线程中，将信号量为1的信号进行p操作
        sem_wait(&sem_p);

        printf("%c",ch);
        fflush(stdout);

        //第五步：当执行完之后需要将信号量初始值为0的执行v操作
        sem_post(&sem_g);
    }
}

int main(int argc, char const *argv[])
{
    //第二步 初始化
    sem_init(&sem_g,0,0);
    sem_init(&sem_p,0,1);

    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,pthread_g,NULL);
    pthread_create(&tid2,NULL,pthread_p,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("\n");

    // 第七步 销毁
    sem_destroy(&sem_g);
    sem_destroy(&sem_p);
    return 0;
}
