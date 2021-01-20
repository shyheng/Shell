#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void fun()
{
    printf("shy \n");
    
    // 使用return
    //return 除了可以返回值以外，主函数中使用可以退出进程，但在子函数中只能退出当前函数
    return ;
    //使用exit
    exit(0);

    // 使用_exit
    _exit(0);

    printf("welcome\n");
}

int main(int argc, char const *argv[])
{
    printf("hello");

    fun();

    printf("shy");
    return 0;
}
