#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    printf("uid=%d, gid=%d\n", getuid(), getgid());
    exit(0);
}
