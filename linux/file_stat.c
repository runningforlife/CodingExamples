#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file0> <file1> ....\n", argv[0]);
        exit(1);
    }

    int i;
    struct stat file_stat;
    char *stat_str;
    for (i = 1; i < argc; ++i) {
        if (stat(argv[i], &file_stat) < 0) {
            printf("fail to get %s stat\n", argv[i]);
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) {
            stat_str = "regular";
        } else if (S_ISDIR(file_stat.st_mode)) {
            stat_str = "directory";
        } else if (S_ISBLK(file_stat.st_mode)) {
            stat_str = "block";
        } else if (S_ISCHR(file_stat.st_mode)) {
            stat_str = "character special";
        } else if (S_ISLNK(file_stat.st_mode)) {
            stat_str = "symbolic link";
        } else if (S_ISFIFO(file_stat.st_mode)) {
            stat_str = "fifo pipe";
        } else {
            stat_str = "unknown mode";
        }

        printf("%s is %s\n", argv[i], stat_str);
    }


    exit(0);
}