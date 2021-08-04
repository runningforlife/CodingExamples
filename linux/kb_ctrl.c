#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
    int key_fd = -1;
    if ((key_fd = open("/dev/kfd", O_RDWR, S_IRUSR | S_IWUSR)) < 0) {
	printf("fail to open, errno= %d", errno);
        exit(-1);
    }

    if (ioctl(key_fd, KDSETLED, LED_NUM | LED_CAP | LED_SCR) < 0) {
        printf("fail to do ioctl, errno=%d", errno); 
        exit(-1);
    }

    exit(0);
}
