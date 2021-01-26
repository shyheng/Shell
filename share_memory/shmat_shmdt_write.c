#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

typedef struct
{
    int a;
    int b;
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

    //使用shmat函数映射共享内存
    // char *text;
    SHM *text;
    if ((text = shmat(shmid,NULL,0)) == (void *)-1)
    {
        perror("out");
        exit(1);
    }
    
    //通过shmat的返回值对共享内存操作
    // strcpy(text,"hello");
    text->a = 100;
    text->b = 'w';

    //操作完毕后要接触共享内存的映射
    if (shmdt(text) == -1)
    {
        perror("out");
        exit(1);
    }
    
    return 0;
}
