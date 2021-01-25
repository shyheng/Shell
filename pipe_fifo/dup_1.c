#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //通过dup函数复制一个文件描述符
    int fd;
    //du执行后返回值文件描述符的文件描述符中最小可用文件描述符
    fd = dup(1);
    printf("fd = %d",fd);

//由于dup函数将这个1复制了一份，所以fd相当于1，向终端写数据
    write(fd,"shy\n",strlen("shy\n"));
    return 0;
}
