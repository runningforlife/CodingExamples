#include<sys/eventfd.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

/* a producer/consumer model based on eventfd */

#define MAX_EVENTS 10
#define MAX_BUF_SIZE 100
#define DEBUG 1

#define ULL unsigned long

#define handle_error(msg) \
     do { perror(msg); exit(EXIT_FAILURE); } while(0)

struct thread_data {
    int epfd;
    void* buf;
} thread_data;

// producer routine: (1) create eventfd (2) epoll_ctl (3) read input/save it to buf, notify consumer
static void* do_producer_work(void* arg) {
    int epfd, n;
    char buf[MAX_BUF_SIZE];
    struct epoll_event event;

    struct thread_data data = *(struct thread_data*)arg;
    epfd = data.epfd;
    if (epfd < 0) {
        handle_error("fail to create event fd");
    }

    pthread_detach(pthread_self());

    for (;;) {
        memset(buf, 0, sizeof(buf));
        int cnt = fgets(buf, sizeof(buf), stdin);
        if (cnt < 0) {
            handle_error("fgets");
        }
        if (strlen(buf) > 0) {
            printf("producer input: %s\n", buf);
            if (DEBUG) {
                strcpy(data.buf, buf);
            }
        }
        int efd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK);
        if (efd < 0) {
            handle_error("eventfd");
        }
        
        event.data.fd = efd;
        event.events = EPOLLET | EPOLLOUT;
        if (epoll_ctl(epfd, EPOLL_CTL_ADD, efd, &event) == -1) {
            handle_error("epoll_ctl");
        }
        // write it to eventfd
        int wcnt = eventfd_write(efd, (ULL)1);
        if (wcnt < 0) {
            handle_error("eventfd_write");
        }
    }
}

// consumer: read from eventfd and print it on output
static void* do_cusumer_work(void* arg) {
    int epfd, n;
    char buf[MAX_BUF_SIZE];
    eventfd_t val;

    struct thread_data data = *(struct thread_data*)arg;
    epfd = data.epfd;
    if (epfd < 0) {
        handle_error("wrong event fd");
    }

    pthread_detach(pthread_self());

    struct epoll_event read_events[MAX_EVENTS];

    for (;;) {
        int ready_fds = epoll_wait(epfd, read_events, MAX_EVENTS, -1);
        if (ready_fds < 0) {
            handle_error("epoll_wait");
        }

        memset(buf, 0, sizeof(buf));
        for (n = 0; n < ready_fds; ++n) {
            if (eventfd_read(read_events[n].data.fd, &val) != -1) {
                printf("eventfd from: %d, value %lld\n", read_events[n].data.fd, val);
                strcpy(buf, data.buf);
                if (strlen(buf) > 0) {
                    write(STDOUT_FILENO, buf, strlen(buf));
                    if (DEBUG) {
                        printf("consumer output: %s\n", buf);
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    
    struct thread_data data;
    int epfd = epoll_create1(0);
    data.epfd = epfd;

    char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    data.buf = buf;

    pthread_t prod_pid, consumer_pid;
    if (pthread_create(&prod_pid, NULL, &do_producer_work, &data) != 0) {
        handle_error("pthread_create");
    }
    if (pthread_create(&consumer_pid, NULL, &do_cusumer_work, &data) != 0) {
        handle_error("pthread_create");
    }

    pthread_join(prod_pid, NULL);
    pthread_join(consumer_pid, NULL);

    // end
    if (DEBUG) {
        printf("exit");
    }
    return 0;
}