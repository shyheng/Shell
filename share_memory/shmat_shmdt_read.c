#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

typedef struct
{
    int a;
    char b;
}SHM;

int main(int argc, char const *argv[])
{
    // 使用ftok函数获取键值
    key_t mykey;
    if ((mykey= ftok(".",100)) == -1)
    {
        perror("out");
        exit(1);
    }
    
    //通过shmget函数创建
    int shmid;
    if ((shmid = shmget(mykey,500,IPC_CREAT | 0666))== -1)
    {
        perror("out");
        exit(1);
    }
    
    system("ipcs -m");

    //映射共享内存的地址
    // char *text;
    SHM *text;
    if ((text = shmat(shmid,NULL,0)) == (void *)-1)
    {
        perror("out");
        exit(1);
    }
    
    //获取共享内存中的数据
    // printf("text = %s\n",text);
    printf("a = %d,b = %d",text->a,text->b);

    //解除共享内存映射
    if (shmdt(text) == -1)
    {
        perror("out");
        exit(1);
    }
    
    return 0;
}
