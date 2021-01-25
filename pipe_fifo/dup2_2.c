#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int fd1;
    //如果使用dup2，则需要实现第二个参数对应变量初始值
    int fd2 = 3;
    
    //将1复制一份为fd2，所以fd2是标准输出
    dup2(1,fd2);
    printf("fd2 = %d\n",fd2);

    fd1 = open("test.txt",O_CREAT | O_RDWR,0664);

    //输出重定向：关闭文件描述符1，将fd1复制一份为1，所以1此时标识的是test.txt文件
    dup2(fd1,1);
    printf("shy\n");

    //再次实现标准输出：关闭文件描述1，将fd2复制一份为1，所以1标识是标准
    dup2(fd1,1);
    printf("zph\n");
    return 0;
}
