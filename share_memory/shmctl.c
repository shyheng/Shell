#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
    //使用ftok函数获取键值
    key_t key;
    if((key = ftok(".",100))==-1)
    {
        perror("out");
        exit(1);
    }

    //使用shmget获取
    int shmid;
    if ((shmid = shmget(key,500,IPC_CREAT | 0666)) == -1)
    {
        perror("out");
        exit(1);
    }
    printf("shmid = %d",shmid);
    system("ipcs -m");

    //通过shmctl函数删除共享内存
    if (shmctl(shmid,IPC_RMID,NULL) == -1)
    {
        perror("out");
        exit(1);
    }
    
    system("ipcs -m");
    return 0;
}
