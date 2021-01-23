#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //使用pipe创建一个无名管道
    int fd_pipe[2];
    if (pipe(fd_pipe) == -1)
    {
        perror("on");
        exit(1);
    }
    printf("fd[0]%d\n",fd_pipe[0]);
    printf("fd[1]%d\n",fd_pipe[1]);
    
    //对无名管道执行读写操作
    // 由于无名管道给当前用户进程两个文件描述符，所以只要操作这两个文件
    // 描述符就可以操作无名管道，所以通过文件IO对无名管道进行操作

    //通过write函数向无名管道写入数据
    //fd_pipe[1]负责写
    if (write(fd_pipe[1],"shy",12) == -1)
    {
        perror("out");
        exit(1);
    }
//如果管道中有数据，再次写入，不会把之前的数据替换
    write(fd_pipe[1],"sssshy",strlen("shyyyyy")+1);
    //通过read函数从无名管道中读取数据
    //fd_pipe[0]负责读
    char buf[32] = "";
    ssize_t by;
    if ( (by = read(fd_pipe[0],buf,sizeof(buf)))== -1)
    {
        perror("out");
        exit(1);
    }
    //如果管道中没有数据，继续读取，则read函数就会阻塞等待
    printf("buf = %s\n",buf);
    printf("%ld\n",buf);
    return 0;
}
