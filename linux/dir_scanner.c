#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

void scan_dir(char *d_name, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    if ((dir = opendir(d_name)) == NULL) {
        fprintf(stderr, "cannot open directory: %s\n", d_name);
        return;
    }

    chdir(d_name);
    while((entry = readdir(dir)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            // ignore . and ..
            if (!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name)) {
                continue;
            }

            printf("%*s%s/\n", depth, "", entry->d_name);
            // scan child dir recursively
            scan_dir(entry->d_name, depth + 4);
        } else {
            printf("%*s%s\n", depth, "", entry->d_name);
        }
    }

    chdir("..");
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dirctory>\n", argv[0]);
        exit(0);
    }
    char *topdir = ".";

    topdir = argv[1];
    printf("scanned directory is %s\n", topdir);
    scan_dir(topdir, 0);

    printf("done\n");
    exit(0);
}