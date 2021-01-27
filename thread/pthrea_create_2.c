#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int num =100;
// 线程函数可以认为是一个普通的全局函数
// 与普通函数不同的是，一个有顺序，一个没有
void *pthread_fun1(void *arg)
{
    printf("num1 = %d",num);
    num++;

    int n = *(int*)arg;
    printf("n = %d",n);
    *(int*)arg = 11;
}

void *pthread_fun1(void *arg)
{
    sleep(1);
    printf("num2 = %d",num);

    int n = *(int*)arg;
    printf("n = %d",n);
}

int main(int argc, char const *argv[])
{
    pthread_t thread1,thread2;

    int a = 66;
    
    if(pthread_create(&thread1,NULL,pthread_fun1,(void *)&a)  != 0)
    {
        perror("out");
        exit(1);
    }
    
    if(pthread_create(&thread1,NULL,pthread_fun1,(void *)&a)  != 0)
    {
        perror("out");
        exit(1);
    }

    return 0;
}
