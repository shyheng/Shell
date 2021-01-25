#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define FIFONAME "test"

int main(int argc, char const *argv[])
{
    //通过mkfifo函数创建有名管道
    if (mkfifo(FIFONAME,0664) == -1)
    {
        if (errno != EEXIST)
        {
            perror("out");
            exit(1);
        }
    }

    //对有名管道进行操作
    //通过open函数打开管道文件并得到文件描述符
    int fd;
    fd = open(FIFONAME,O_RDWR);
    if (fd == -1)
    {
        perror("out");
        exit(1);
    }
    
    //通过write函数向管道中写入数据
    if (write(fd,"shy",12) == -1)
    {
        perror("out");
        exit(1);
    }
    
    write(fd,"zph",12);

    //通过read函数读取管道中的数据
    char buf[32] ="";
    if (read(fd,buf,sizeof(buf))== -1)
    {
        perror("out");
        exit(1);
    }
     
     printf("buf = %s",buf);

     //使用close函数关闭文件描述符
     close(fd);

    return 0;
}