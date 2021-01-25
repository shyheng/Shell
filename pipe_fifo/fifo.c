#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    //通过mkfifo函数创建有名管道
    if (mkfifo("test",0664) == -1)
    {
        // printf("errno=%d\n",errno);
        //文件存在错误，排除
        if (errno != EEXIST)
        {
            perror("out");
            exit(1);
        }
    }
    return 0;
}