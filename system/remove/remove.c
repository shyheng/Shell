#include <stdio.h>

int main()
{
    //使用remove删除文件
    if(remove("./file.txt")==-1)
    {
        perror("out");
        return -1;
    }
    return 0;
}