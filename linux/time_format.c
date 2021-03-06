#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    time_t t;
    struct tm  *tmp;

    char buf1[16];
    char buf2[64];

    time(&t);
    tmp = localtime(&t);

    if (!strftime(buf1, 16, "time and date: %r, %Y %m %d", tmp)) {
        printf("time buffer is too small\n");
    } else {
        printf("%s\n", buf1);
    }

    if (!strftime(buf2, 64, "%r, %Y %m %d", tmp)) {
        printf("time buffer is too small\n");
    } else {
        printf("%s\n", buf2);
    }
}
