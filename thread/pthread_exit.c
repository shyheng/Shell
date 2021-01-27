#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun(void *a)
{
    printf("子线程执行\n");

    static char buf[] = "shy";

    int i;
    for(i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            //通过pthread_exit函数退出当前线程
            // pthread_exit(NULL);
            pthread_exit(buf);
        }
        
        printf("***********");
        sleep(1);
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

    // pthread_join(thread,NULL);
    char *str;
    pthread_join(thread,(void **)&str);
    printf("str = %s \n",str);

    printf("退出");
    return 0;
}
