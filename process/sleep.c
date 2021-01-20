#include <stdio.h>
#include  <unistd.h>

int main(int argc, char const *argv[])
{
    while(1)
    {
        printf("shy\n");

        //当运行到睡眠2秒，就绪态
        sleep(2);
    }
    return 0;
}
