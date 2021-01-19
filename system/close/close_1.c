#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main()
{
    int fd;
    fd = open("file.txt",O_RDONLY);

    if(fd == -1)
    {
         perror("fail on");
        return -1;
    }

    printf("%d\n",fd);

    //关闭了，就无法在使用，用，在创建一个
    close(fd);
    return 0;
}