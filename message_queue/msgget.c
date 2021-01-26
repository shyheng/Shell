#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char const *argv[])
{
    //通过ftok函数获取ipc
    key_t mykey;
    if (mykey = ftok(".",100)==-1)
    {
        perror("out");
        exit(1);
    }
    
    printf("mykey = %#x\n",mykey);

    //通过msgget函数创建一个消息队列
    int msqid;
    if((msqid = msgget(mykey,IPC_CREAT | 0666))==-1)
    {
        perror("out");
        exit(1);
    }

    printf("msqid = %d",msqid);

    system("ipcs -q");
    return 0;
}
