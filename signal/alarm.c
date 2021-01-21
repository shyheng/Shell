#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
     unsigned int src;
    //设置闹钟5秒  代码会接着往下执行 当设定时间到后 会产生SIGINT信号

    // 如果alarm之前没有设置其他闹钟，则返回0 如果有设置返回剩余秒数
    // 如果一个程序出现多个alarm闹钟 第一个如果没有到达时间遇到第二个
    // 则第一个闹钟清除，按照第二个闹钟的闹钟继续向下执行
    
    src = alarm(5);
    printf("%d",src);
    sleep(3);

    src = alarm(6);
    printf("%d",src);
    while(1)
    {
        printf("shy\n");
        sleep(1);
    }
    return 0;
}
