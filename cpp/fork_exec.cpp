#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
	printf("wrong args\n");
	return  0;
    }

    char *args[] = {NULL, "hi", "world", NULL};
    args[0] = argv[1];

    pid_t pid = fork();
    if (pid == 0) {
        execve(argv[1], args, NULL);
    }

    printf("main exit\n");
}
