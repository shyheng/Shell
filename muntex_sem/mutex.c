#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//通过互斥锁解决线程
int money = 10000;

//第一步：创建互斥锁（由于两线程操作同一个互斥锁，所以定义在全局
pthread_mutex_t mymutex;

void *pthread_fun1(void *arg)
{
    int get,yu,shiji;
    get = 10000;

    //第三步：对共享资源的操作进行上锁
    pthread_mutex_lock(&mymutex);

    printf("张查询\n");
    sleep(1);
    yu = money;

    printf("张取\n");
    sleep(1);
    if (get > yu)
    {
        shiji = 0;
    }
    else
    {
        shiji = get;
        yu = yu -get;
        money =yu;
    }

    printf("张想取出%d,实际%d，余额%d",get,shiji,yu);
    
    //第四步：当共享资源的操作进行完毕，进行解锁
    pthread_mutex_unlock(&mymutex);
    
    pthread_exit(NULL);
}

void *pthread_fun2(void *arg)
{
    int get,yu,shiji;
    get = 10000;

    //第三步：对共享资源的操作进行上锁
    pthread_mutex_lock(&mymutex);

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
        money =yu;
    }

    printf("李想取出%d,实际%d，余额%d",get,shiji,yu);

    //第四步：当共享资源的操作进行完毕，进行解锁
    pthread_mutex_unlock(&mymutex);
    
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{

    //第二步 初始化互斥锁
    pthread_mutex_init(&mymutex,NULL);

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

    //第五步：销毁互斥锁
    pthread_mutex_destroy(&mymutex);
    return 0;
}
