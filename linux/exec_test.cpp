#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
		printf("wrong arguments\n");
        return 0;
    }

    char *cmdPath = argv[1];
    printf("cmd path is %s\n", cmdPath);

    pid_t pid = fork();
    if (pid < 0) return 0;

    if (pid == 0) {
		execvp(cmdPath, NULL);
    } else  if (pid > 0) {
		int status;
        pid_t wpid = waitpid(pid, &status, 0);
        if (wpid == -1) {
            printf("waitpid error\n");
            exit(EXIT_FAILURE);
        }		

        if (WIFEXITED(status)) {
            printf("exited, status=%s\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("killed by signal %d\n", WTERMSIG(status));
        } else if (WIFSTOPPED(status)) {
            printf("stopped by signal %d\n", WSTOPSIG(status));
        } else if (WIFCONTINUED(status)) {
            printf("continued\n");
        }
    }
}
