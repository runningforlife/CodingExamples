/* whether we use pthread lib */
#include <iostream>

#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static sigset_t sigmask;
void initSigHandler() {
	signal(SIGALRM, SIG_IGN);
	sigemptyset(&sigmask);
	sigaddset(&sigmask, SIGALRM);
	sigaddset(&sigmask, SIGINT);
	if (pthread_sigmask(SIG_BLOCK, &sigmask, NULL) != 0) {
		printf("pthread sigmask fail: %s", strerror(errno));
	}
}

__attribute__((weak))
int pthread_create(pthread_t*, const pthread_attr_t*, void* (*)(void *), void*);


void* thr_func1(void *args) {
	pthread_detach(pthread_self());
	char *ptr = (char*)args;
	std::cout << "thr_func1:" << ptr << std::endl;
	printf("%s\n", ptr);

	alarm(5);

	int signo;
	if (sigwait(&sigmask, &signo) != 0) {
		switch (signo) {
			case SIGALRM:
				printf("rcv signal alarm\n");
				alarm(0);
				break;
			case SIGINT:
				printf("rcv signal interrupt\n");
				break;
			default:
				printf("unkown signal\n");
				break;
		}
	}
};

void* thr_func2(void *args) {
	std::cout << "thr_func2" << std::endl;

	char *ptr = new char[16];
	strncpy(ptr, "hello", 6);

	pthread_t tid;
	if (pthread_create(&tid, NULL, thr_func1, ptr) != 0) {
		std::cerr << "fail to create child thread" << std::endl;
	}

	pthread_join(tid, NULL);
	//std::cout << "all threads exit" << std::endl;
}


int main()
{
	if (pthread_create) {
		std::cout << "This is a multi-thread version!" << std::endl;
	} else {
		std::cout << "This is single-thread version!" << std::endl;
	}

	pthread_t tid;
	if (pthread_create(&tid, NULL, thr_func2, NULL) != 0) {
		std::cout << "fail to create child thread" << std::endl;
	}

	pthread_join(tid, NULL);
	printf("main exit\n");
}

