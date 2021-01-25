#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//重定向
int main(int argc, char const *argv[])
{
    int fd_file;
    fd_file = open("text.txt",O_WRONLY | O_CREAT | O_TRUNC,0664);
    if(fd_file == -1);
    {
        perror("out");
        exit(1);
    }

    close(1);

    int fd = dup(fd_file);
    printf("shy\n");
    printf("fd = %d",fd);

    return 0;
}
