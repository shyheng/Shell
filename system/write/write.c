#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main()
{
    //向终端写入数据
    //对1这个文件描述符进行操作
    if(write(1,"hello shy6\n",12) == -1)
    {
        perror("to");
        return -1;
    }


    return 0;
}