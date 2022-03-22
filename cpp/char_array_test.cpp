/* char array examples in c */
#include <stdio.h>
#include <string.h>

const static char *SERVICES[] = {"mount-proc-sys","udev", "hostname","depmod", 
                "modules", "filesystems", "inetd", 0};

int main(void) {

    const char **p = SERVICES;

    while (*p != NULL) {
        printf("service: %s\n", *p);
        ++p;
   }

}
