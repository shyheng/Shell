#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//使用无名管道实现父子进程的通信
//由于无名管道创建之后给当前进程两个文件描述符，
// 所以如果两个完全不相关的进程 无法获取一个无名管道的文件描述符
int main(int argc, char const *argv[])
{
    //创建无名管道
    int pipefd[2];
    if(pipe(pipefd) == -1)
    {
        perror("out");
        exit(1);
    }

    //使用fork函数创建子进程
    pid_t pid;
    if((pid = fork()) < 0)
    {
        perror("out");
        exit(1);
    }
    else if(pid > 0)//父进程
    {
        char buf[128] = {};
        while (1)
        {
            //从终端读取数据
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf) - 1] = '\0';

            if (write(pipefd[1],buf,sizeof(buf))== -1)
            {
                perror("out");
                exit(1);
            }
        }
    }
    else //子进程
    {
        //子进程接受父进程的数据
        char buf[128] = "";
        while (1)
        {
            if (read(pipefd[0],buf,sizeof(buf))== -1)
            {
                perror("out");
                exit(1);
            }
            printf("son%s\n",buf);
        }
        
    }
    return 0;
}
