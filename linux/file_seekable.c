#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main(int argc , char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    int fd;
    off_t offset;
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        printf("fail to open: %s\n", strerror(errno));
        exit(1);
    }

    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("File is not seekable\n");
    } else {
        printf("File is seekable\n");
    }
}