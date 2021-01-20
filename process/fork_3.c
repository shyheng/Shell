#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd;
    if((fd = open("file.txt",O_RDONLY))== -1)
    {
        perror("nos");
        return -1;
    }

    //子进程会继承父进程一些公有的区域，比如磁盘空间，内核空间
    // 文件描述符的偏移量保存在内核中，所以父进程改变偏移量，子进程紧随其后

     pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("no");
        return -1;
    }
    else if(pid > 0)//父进程的代码区
    {
        printf("fa");

        char buf[32] = "";
        if (read(fd,buf,30)== -1)
        {
            perror("out");
            return -1;
        }
        
        printf("%s",buf);
    }
    else //子进程代码区
    {
        sleep(1);
        printf("son");

        char buf[32] = "";
        if (read(fd,buf,30)== -1)
        {
            perror("out");
            return -1;
        }
        
        printf("%s",buf);
    }

    while (1)
    {
        
    }
    
    return 0;
}
