#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //创建有名管道
    // 为了实现两个进程都可以发数据，所有创建两个有名管道
    if (mkfifo("shy",0644)==-1)
    {
        if (errno != EEXIST)
        {
            perror("out");
            exit(1);
        }
    }
    
    if (mkfifo("shy1",0644)==-1)
    {
        if (errno != EEXIST)
        {
            perror("out");
            exit(1);
        }
    }

    //打开有名管道，并得到文件描述符
    int fd_w,fd_r;
    if ((fd_r = open("shy",O_RDONLY))== -1)
    {
        perror("out1");
        exit(1);
    }
    
    if ((fd_w = open("shy1",O_WRONLY))== -1)
    {
        perror("out2");
        exit(1);
    }
    
    char buf[128] = "";
    ssize_t bytes;
    while (1)
    {
        //send 向shy写入数据 ，从shy1读数据
        if (bytes = read(fd_r,buf,sizeof(buf))==-1)
        {
            perror("out3");
            exit(1);
        }
        printf("buf = %s",buf);

        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0';
        
        write(fd_w,buf,sizeof(buf));


        
    }
    
    return 0;
}
