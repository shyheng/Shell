#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main()
{
    //测试一个进程(一个程序)创建文件描述个数
    //一个程序运行的时候最多可以创建1024个文件，0~1023
#if 1
    int fd;
    while (1)
    {
        fd = open("file.txt",O_RDONLY | O_CREAT,0664);

        if(fd == -1)
        {
            perror("out");
            return -1;
        }

        printf("%d\n",fd);
    }
#endif

// 测试文件描述值的规律
// 文件描述从大到小创建
// 如果有关闭,则在创建
// 注意不要认为最后创建是最大的
#if 0
    int fd1,fd2,fd3,fd4;
    fd1 = open("test.txt",O_RDONLY | O_CREAT,0664);
    fd2 = open("test.txt",O_RDONLY | O_CREAT,0664);
    fd3 = open("test.txt",O_RDONLY | O_CREAT,0664);
    fd4 = open("test.txt",O_RDONLY | O_CREAT,0664);

    printf("%d\n",fd1);
    printf("%d\n",fd2);
    printf("%d\n",fd3);
    printf("%d\n",fd4);

    close(fd2);
    int fd5,fd6;
    fd5 = open("test.txt",O_RDONLY | O_CREAT,0664);
    fd6 = open("test.txt",O_RDONLY | O_CREAT,0664);
    printf("%d\n",fd5);
    printf("%d\n",fd6);


#endif

    return 0;
}