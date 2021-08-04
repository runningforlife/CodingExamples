#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

#define ROOT_DIR "/"
#define CUR_DIR "."
#define PREV_DIR ".."


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s dir_name\n", argv[0]);
        exit(0);
    }

    char *dir_name = argv[1];

    struct DIR *dir;
    struct dirent *dentry;
    char d_name_cur[256], d_name_prev[256];
    //int ino_cur, ino_prev;
    char buf[256] = {0, };

    chdir(dir_name);
    printf("current working dir: %s\n", getcwd(buf, 256));

    if ((dir = opendir(dir_name)) == NULL) {
        printf("fail to open dir: %s\n", strerror(errno));
        exit(1);
    }

    while ((dentry = readdir(dir)) != NULL) {
	    if (!strncmp(dentry->d_name, CUR_DIR, 256)) {
            strncpy(d_name_cur, dentry->d_name, 256);
            printf("%s ino is %d\n", dentry->d_name, dentry->d_ino);
        } else if (!strncmp(dentry->d_name, PREV_DIR, 256)) {
            strncpy(d_name_prev, dentry->d_name, 256);
            printf("%s ino is %d\n", dentry->d_name, dentry->d_ino);
        }
    }

    if (!strncmp(d_name_cur, d_name_prev, 256)) {
        printf("%s is equal to %s\n", d_name_cur, d_name_prev);
    } else {
        printf("%s is not equal to %s\n", d_name_cur, d_name_prev);
    }

    exit(0);
}
