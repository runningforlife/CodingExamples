#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("current uid=%d, euid=%d\n", (int)getuid(), (int) geteuid());
	
	int uid = atoi(argv[1]);
	printf("set euid to %d\n", uid);

	if (setuid(uid) != 0) {
		printf("setuid(): error: %s", strerror(errno));
	} else {
		printf("after setuid, uid=%d, euid=%d\n", (int)getuid(), (int)geteuid());
	}
}
