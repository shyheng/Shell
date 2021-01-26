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

    //通过msgrcv函数接受消息的信息
    //注意如果没有第四个参数指定消息时，msgrcv会阻塞等待
    MSG msg;
    // 遵循先进先出
    // if (msgrcv(msgid,&msg,MSGTEXT_SIZE,0,0)== -1)
    //获取当前类型的数据类型的数据
    // if (msgrcv(msgid,&msg,MSGTEXT_SIZE,2,0)== -1)
    //获取绝对值最小的
    if (msgrcv(msgid,&msg,MSGTEXT_SIZE,-3,0)== -1)
    {
        perror("out");
        exit(1);
    }

    printf("rcv = %s\n",msg.msg_text);

    system("ipcs -q");

    return 0;
}