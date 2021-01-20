#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clear_fun1(void)
{
    printf("shy1\n");
}

void clear_fun2(void)
{
    printf("shy2\n");
}

void clear_fun3(void)
{
    printf("shy3\n");
}

int main(int argc, char const *argv[])
{
    //atexit函数在进程结束时才会调用
    // atexit 多次调用后 执行顺序与调用顺序相反
    atexit(clear_fun1);
    atexit(clear_fun2);
    atexit(clear_fun3);
    printf("shy main\n");
    sleep(3);
    return 0;
}
