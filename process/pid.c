#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//进程
int main(int argc, char const *argv[])
{
    //获取当前进程号
    printf("%d\n",getpid());

    // 获取当前父进程
    printf("%d\n",getppid());

    // 获取当前进程所在组
    printf("%d\n",getpgid(getpid()));

    while (1)
    {
        
    }
    
    return 0;
}
