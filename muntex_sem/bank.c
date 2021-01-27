#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int money = 10000;

void *pthread_fun1(void *arg)
{
    int get,yu,shiji;
    get = 10000;

    printf("张查询\n");
    sleep(1);
    yu = money;

    printf("张取\n");
    sleep(1);
    if (get > yu)
    {
        shiji = get;
        yu = yu -get;
    }

    printf("张想取出%d,实际%d，余额%d",get,shiji,yu);
    
    pthread_exit(NULL);
}

void *pthread_fun2(void *arg)
{
    int get,yu,shiji;
    get = 10000;

    printf("李查询\n");
    sleep(1);
    yu = money;

    printf("李取\n");
    sleep(1);
    if (get > yu)
    {
        shiji = 0;
    }
    else
    {
        shiji = get;
        yu = yu -get;
    }

    printf("李想取出%d,实际%d，余额%d",get,shiji,yu);
    
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tid1,tid2;

    if (pthread_create(&tid1,NULL,pthread_fun1,NULL) != 0)
    {
        perror("out");
        exit(1);
    }

    if (pthread_create(&tid2,NULL,pthread_fun2,NULL) != 0)
    {
        perror("out");
        exit(1);
    }

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
