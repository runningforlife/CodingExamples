#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("wrong arguments\n");
        printf("Usage: %s <file_descriptor>\n", argv[0]);
        exit(1);
    }

    int val;
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0) < 0)) {
        printf("fail to fcntl for %d\n", atoi(argv[1]));
        exit(1);
    }

    printf("access mode val: %d\n", val);

    switch (val & O_ACCMODE)
    {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            printf("unknown access mode");
            break;
    }

    if (val & O_APPEND) {
        printf(", append");
    }

    if (val & O_NONBLOCK) {
        printf(", non-blocking");
    }

    if (val & O_SYNC) {
        printf(", synchronous writes");
    }

    putchar('\n');
    exit(0);
}