#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define N 128

typedef struct 
{
    long msg_type;//消息类型，必须是第一个，必须是long
    char msg_text[N];//消息正文，也可以有多个成员并且类型可以任意
}MSG;

#define MSGTEXT_SIZE (sizeof(MSG) - sizeof(long))

int main(int argc, char const *argv[])
{
    //使用ftok函数获取键值
    key_t key;
    if ((key = ftok(".",100))== -1)
    {
        perror("out");
        exit(1);
    }
    
    //使用msgget函数创建一个消息队列
    int msgid;
    if ((msgid = msgget(key,IPC_CREAT | 0777))== -1)
    {
        perror("out");
        exit(1);
    }
    
    system("ipcs -q");

    //使用msgsnd函数向消息队列中发送数据
    MSG msg1 = {1,"shy"};
    MSG msg2 = {4,"shy1"};
    MSG msg3 = {2,"shy2"};
    MSG msg4 = {3,"shy3"};
    if (msgsnd(msgid,&msg1,MSGTEXT_SIZE,0) == -1)
    {
        perror("out");
        exit(1);
    }
    
    if (msgsnd(msgid,&msg2,MSGTEXT_SIZE,0) == -1)
    {
        perror("out");
        exit(1);
    }

    if (msgsnd(msgid,&msg3,MSGTEXT_SIZE,0) == -1)
    {
        perror("out");
        exit(1);
    }

    if (msgsnd(msgid,&msg4,MSGTEXT_SIZE,0) == -1)
    {
        perror("out");
        exit(1);
    }

    system("ipcs -q");
    return 0;
}
