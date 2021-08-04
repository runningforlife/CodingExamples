#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>


#define BUF_SIZE 4096

int main(int argc, char **argv) {
    int n;
    char buf[BUF_SIZE];

    while((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            printf("write error: %s\n", strerror(errno));
        }
    }

    if (n < 0) {
        printf("read error\n");
    }
}
