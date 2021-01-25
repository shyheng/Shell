#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    //重定向
    int fd1;
    int fd2;

    fd1 = open("test.txt",O_CREAT | O_WRONLY ,0664);
    if (fd1 < 0)
    {
        perror("out");
        exit(1);
    }

    //首先关闭文件描述符1，然后将fd1复制给1，意味着1和fd1都标识test.txt文件

    fd2 = dup2(fd1,1);
    printf("holle\n");
    printf("fd2 = %d",fd2);
    
    return 0;
}
