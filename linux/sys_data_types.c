#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>


static int sys_conf[5] = {
    _SC_ARG_MAX, _SC_CHILD_MAX, _SC_CLK_TCK, _SC_PAGE_SIZE,
};

static int path_conf[3] = {
    _PC_PATH_MAX, _PC_LINK_MAX, _PC_PIPE_BUF,
};


void pr_pathconf() {
    int res;
    #ifdef _PC_PATH_MAX
        res = pathconf("/", _PC_PATH_MAX);
        if (res < 0) {
            if (errno != 0) {
                if ( errno == EINVAL) {
                    printf("no symbol defined for PATH_MAX\n");
                } else {
                    printf("path error = %s\n", strerror(errno));
                }
            } else {
                printf("no limit for PATH_MAX\n");
            }
        } else {
            printf("PATH_MAX=%ld\n", res);
        }
    #endif

    #ifdef _PC_PIPE_BUF
        res = pathconf("/", _PC_PIPE_BUF);
        if (res < 0) {
            if (errno != 0) {
                if ( errno == EINVAL) {
                    printf("no symbol defined for PATH_MAX\n");
                } else {
                    printf("path error = %s\n", strerror(errno));
                }
            } else {
                printf("no limit for PATH_MAX\n");
            }
        } else {
            printf("PIPE_BUF=%ld\n", res);
        }
    #endif
}

void pr_sysconf() {
    int res;
    #ifdef ARG_MAX
        printf("ARG_MAX value = %ld\n", (long)ARG_MAX + 0);
    #else
        printf("ARG_MAX no defined\n");
    #endif

    #ifdef _SC_ARG_MAX
        res = sysconf(_SC_ARG_MAX);
        if (errno != EINVAL) {
            printf("ARG_MAX=%ld\n", res);
        } else {
            printf("no _SC_ARG_MAX defined\n");
        }
    #endif

    #ifdef _SC_CHILD_MAX
        res = sysconf(_SC_CHILD_MAX);
        if (res != EINVAL) {
            printf("CHILD_MAX=%ld\n", res);
        } else {
            printf("no symbol found\n");
        }
    #endif

    #ifdef _SC_CLK_TCK
        res = sysconf(_SC_CLK_TCK);
        if (res != EINVAL) {
            printf("CLK TCK=%ld\n", res);
        } else {
            printf("no symbol found for SC_CLK_TCK");
        }
    #endif
}

int main(int argc, char **argv) {

    pr_sysconf();

    pr_pathconf();

    return 0;
}