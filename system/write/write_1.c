#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main()
{
    //向文件写入数据
    int fd;
    //以只写的方式，如果文件不存在则创建
    fd = open("file.txt",O_WRONLY | O_CREAT | O_TRUNC ,0664);
    if(fd == -1)
    {
        perror("no");
        return -1;
    }

//使用write函数向文件写入数据
    if(write(fd,"hello shy\n",12)== -1)
    {
        perror("out");
        return -1;
    }

    //关闭文件描述符
    close(fd);

    return 0;
}