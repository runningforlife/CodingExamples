#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#define MSG_LEN 512

int main(int argc, char *argv[])
{
    char *server_ip = NULL;
    int port;

    int fd, res;
    int opt_val = 1;
    char msg_buf[MSG_LEN] = {0, };
    struct sockaddr_in s_addr;
    memset(&s_addr, sizeof(s_addr), 0);

    int opt;
    int set_reuse_opt = 0;
    int is_tcp_server = 0;
    while ((opt = getopt(argc, argv, "s:p:t:u:r")) != -1) {
		switch (opt) {
			case 's':
				server_ip = optarg;
				break;
			case 'p':
				port = atoi(optarg);
				break;
			case 'r':
				set_reuse_opt = 1;
				break;
			case 't':
				is_tcp_server = 1;
				break;
			case 'u':
				is_tcp_server = 0;
				break;
			default:
				printf("unknow args\n");
		}
    }

    if (!is_tcp_server) {
		fd = socket(AF_INET, SOCK_DGRAM, 0);
    } else {
		fd = socket(AF_INET, SOCK_STREAM, 0);
    }
    if (fd < 0) {
		printf("fail to create socket: %d\n", fd);
		exit(-1);
    }

    if (set_reuse_opt) {
		if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(int)) < 0) {
			printf("fail to set sock opt: %s\n", strerror(errno));
			exit(0);
		}

		/*if (setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &opt_val, sizeof(int)) < 0) {
			printf("fail to set sock opt of reuseport\n");
			exit(0);
		}*/
    }
    
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);

    printf("server ip is %s\n", server_ip);
    if (server_ip == NULL || inet_aton(server_ip, &s_addr.sin_addr) == 0) {
		printf("invalid address\n");
		s_addr.sin_addr.s_addr = INADDR_ANY;
    }

    if (bind(fd, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0) {
		printf("fail to bind addr: %s\n", strerror(errno));
		exit(-1);
    }

    if (is_tcp_server) {
		struct sockaddr_in client_addr;
		unsigned int addr_len;
		if (listen(fd, 4) < 0) {
			printf("fail to listen: %s\n", strerror(errno));
			exit(-1);
		}
		
		while (accept(fd, (struct sockaddr *)&client_addr, &addr_len) != -1) {
			printf("accept connection from %s\n", inet_ntoa(client_addr.sin_addr));
		}
    } else {
		printf("udp server is started\n");
		while (recvfrom(fd, (void *)msg_buf, MSG_LEN, 0, NULL, 0) != -1) {
			printf("recv message: %s\n", msg_buf);
        }
    }
}
