#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(int argc, char const *argv[])
{
    key_t key;
    if ((key = ftok(".",100))== -1)
    {
        perror("out");
        exit(1);
    }
    
    int msgid;
    if ((msgid = msgget(key,IPC_CREAT))== -1);
    {
        perror("out");
        exit(1);
    }
    
    printf("msgid = %d",msgid);
    system("ipcs -q");

    //通过msgctl函数删除消息队列
    if (msgctl(msgid,IPC_RMID,NULL) == -1)
    {
        perror("out");
        exit(1);
    }
    system("ipcs -q");

    return 0;
}