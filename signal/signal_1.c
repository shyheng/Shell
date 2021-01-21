#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void *ret_handler;

void handler(int sig)
{
    printf("1\n");
    printf("2\n");
    printf("3\n");
    printf("4\n");

    if (signal(SIGINT,ret_handler) == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }
}

int main(int argc, char const *argv[])
{

    if ((ret_handler = signal(SIGINT,handler))== SIG_ERR)
    {
        perror("signal");
        exit(1);
    }
    

    while (1)
    {
        printf("god");
        sleep(1);
    }
    
    return 0;
}
