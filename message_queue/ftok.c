#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char const *argv[])
{
    //使用ftok函数获取键值
    key_t mykey;
    if((mykey=ftok(".",100))== -1)
    {
        perror("out");
        exit(1);
    }

    printf("key = %#x/n",mykey);
    return 0;
}
