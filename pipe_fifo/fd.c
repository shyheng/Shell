#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    #if 0
    //除了1什么都可以关
    close(0);
    int fd1,fd2,fd3;
    fd1 = open("file.txt",O_RDONLY | O_CREAT,0664);
    fd2 = open("file.txt",O_RDONLY | O_CREAT,0664);
    fd3 = open("file.txt",O_RDONLY | O_CREAT,0664);

    printf("fd1 =%d\n",fd1);
    printf("fd2 =%d\n",fd2);
    printf("fd3 =%d\n",fd3);
    #endif

    #if 1
        int fd;
        //最多打开1024个文件
        while (1)
        {
            if((fd = open("file.txt",O_RDONLY | O_CREAT,0664)) < 0)
            {
                perror("out");
                exit(1);
            }
            printf("fd = %d",fd);
        }
        
    #endif
    return 0;
}
