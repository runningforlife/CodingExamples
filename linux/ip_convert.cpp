#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {

     struct in_addr addr;
     if (inet_aton("192.168.225.1", &addr) == 1) {
        printf("converte ip addr=%0x\n", addr.s_addr);
     }

     char *ip = inet_ntoa(addr);
     printf("orignal ip is %s\n", ip);

     return 0;
}
