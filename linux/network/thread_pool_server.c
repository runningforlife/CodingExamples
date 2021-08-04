/**
* this is a daemon to show use eventfd/thread pool techniques to 
* process mutiple tcp connections from clients
*/

#include<socket_header.h>
#include<pthread.h>

static int MAX_POOL_SIZE = 5;


void thread_main(void* data) {

}

struct task {
    int connect_fd; // accepted socket fd
    void *do_work; // function to execute task
} task;

struct thread_pool {
    int thread_count; // current running threads
    pthread_t tid; // thread id
    pthread_mutex_t mutext; 
} thread_pool;

static void fatal(char *error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server_port>\n", argv[0]);
        exit(EXIT_SUCCESS);
    }


    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {
        fatal("fail to create socket");
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(argv[1]);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock_fd, &server_addr, sizeof(server_addr)) < 0) {
        fatal("fail to bind");
    }

    if (listen(sock_fd, 5) < 0) {
        fatal("fail to listen");
    }

    // keep accept connections from clients
    for (; ;) {
        int cfd;
        if ((cfd = accept(sock_fd, NULL, NULL)) < 0) {
            perror("accept");
            continue;
        }
    }
}