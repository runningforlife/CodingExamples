#include<linux/bpf.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<linux/filter.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<linux/if_packet.h>
#include<net/ethernet.h>
#include<net/if.h>
#include<arpa/inet.h>


// tcpdump dst port 53 -dd
static struct sock_filter filter_code[] = {
    { 0x28, 0, 0, 0x0000000c },
    { 0x15, 0, 6, 0x000086dd },
    { 0x30, 0, 0, 0x00000014 },
    { 0x15, 2, 0, 0x00000084 },
    { 0x15, 1, 0, 0x00000006 },
    { 0x15, 0, 13, 0x00000011 },
    { 0x28, 0, 0, 0x00000038 },
    { 0x15, 10, 11, 0x00000035 },
    { 0x15, 0, 10, 0x00000800 },
    { 0x30, 0, 0, 0x00000017 },
    { 0x15, 2, 0, 0x00000084 },
    { 0x15, 1, 0, 0x00000006 },
    { 0x15, 0, 6, 0x00000011 },
    { 0x28, 0, 0, 0x00000014 },
    { 0x45, 4, 0, 0x00001fff },
    { 0xb1, 0, 0, 0x0000000e },
    { 0x48, 0, 0, 0x00000010 },
    { 0x15, 0, 1, 0x00000035 },
    { 0x6, 0, 0, 0x00040000 },
    { 0x6, 0, 0, 0x00000000 },
};

static struct sock_fprog bpf = {
    .len = sizeof(filter_code)/(sizeof(struct sock_filter)),
    .filter = filter_code,
};

int main(int argc, char *argv[]) {
    int sock_fd, bytes;
    char buf[4096];

    struct sockaddr_ll addr;
    struct iphdr *ip_header;

    struct ifreq ifr;

    char src_addr[INET_ADDRSTRLEN], dst_addr[INET_ADDRSTRLEN];
    char *iface_name;

    if (argc != 2) {
        printf("Usage: %s iface_name\n", argv[0]);
        return 1;
    }

    // 1. create socket
    sock_fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock_fd < 0) {
        perror("socket created failure");
        return 1;
    }
    
    iface_name = argv[1];
    memset(&addr, 0, sizeof(addr));
    addr.sll_ifindex = if_nametoindex(iface_name);
    addr.sll_family = AF_PACKET;
    addr.sll_protocol = htons(ETH_P_ALL);

    // 2. bind socket (no need)
    /*if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("bind device %s failed\n", iface_name);
        return 1;
    }*/

    // 3. attach filter
    if (setsockopt(sock_fd, SOL_SOCKET, SO_ATTACH_FILTER, &bpf, sizeof(bpf)) < 0) {
        perror("attaching filter failed");
        return 2;
    }

    for (;;) {
        bytes = recv(sock_fd, buf, sizeof(buf), 0);
        if (bytes < 1) {
            perror("received data failed");
            return -1;
        }

        ip_header = (struct iphdr *) (buf + sizeof(struct ether_header));
        inet_ntop(AF_INET, &ip_header->saddr, src_addr, sizeof(src_addr));
        inet_ntop(AF_INET, &ip_header->daddr, dst_addr, sizeof(dst_addr));
        printf("IPv%d proto=%d src=%s dest=%s\n", 
                ip_header->version, ip_header->protocol, src_addr, dst_addr);
    }

    return 0;
}
