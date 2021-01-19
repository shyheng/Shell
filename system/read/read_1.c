#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"

int main()
{
    //使用read函数从终端读取数据
    //使用0文件描述从终端读取数据
// str 数组名 
// 想读取字节数

    // 如果终端输入的字节数大于第三个参数
    // 则只会先读取三个字节数,返回值也是与第三个参数一致

    //如果终端输入的数小于第三个
    // 则只会读取输入的数据加上换行符
    char str[32] = "";
    if(read(0,str,6)== -1)
    {
        printf("no");
        return -1;
    }
    printf("%s\n",str);
    return 0;
}