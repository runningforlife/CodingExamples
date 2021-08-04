#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

#define CURRENT_DIR "."
#define PARENT_DIR ".."

int main(int argc, char **argv) {

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    getcwd(buf, sizeof(buf));
    
    printf("current directory is %s\n", buf);
    
    DIR *cur = opendir(CURRENT_DIR);
    if (cur == NULL) {
        printf("fail to open %s", CURRENT_DIR);
        exit(1);
    }
    struct dirent *c = readdir(cur);

    DIR *parent = opendir(PARENT_DIR);
    if (parent < 0) {
        printf("fail to open dir %s", PARENT_DIR);
        exit(1);
    }
    struct dirent *p = readdir(parent);
    

    printf("current dir/parent dir is %s", (!strcmp(c->d_name, p->d_name) ? "equal\n" : "not equal\n"));
}