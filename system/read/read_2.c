#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

#define N 64

int main()
{

    // 从read文件中读取数据
    int fd;
    if((fd=open("test.txt",O_RDONLY | O_CREAT,0664)) == -1)
    {
        perror("out");
        return -1;
    }

    // 读取文件内容
    char buf[N] = "";
    #if 0
    if(read(fd,buf,32)== -1)
    {
        perror("no");
        return -1;
    }
    printf("%s",buf);


    char buf1[N] = "";
    read(fd,buf1,32);
    printf("%s",buf1);

//如果文件中的数据都读取完了，则返回0；
    char buf2[N] = "";
    read(fd,buf2,32);
    printf("%s",buf2);
#endif

//读取文件中的所有内容
    while (read(fd,buf,32) != 0)
    {
        printf("%s",buf);
    }
    
    //关闭文件描述符
    close(fd);
    return 0;
}