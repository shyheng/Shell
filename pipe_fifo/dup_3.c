#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    //实现输出重定向后，标准输出
    int fd1;
    int fd2;
    fd2 = dup(1);
    printf("fd2= %d",fd2);
    
    fd1 = open("test.txt",O_RDWR | O_CREAT,0664);
    
    close(1);
    int fd3 = dup(fd1);
    printf("hello\n");
    printf("fd3 = %d",fd3);

    close(1);
    int fd4 = dup(fd2);
    printf("hello\n");
    printf("fd4 = %d",fd4);

    return 0;
}
