#include <stdio.h>

static void printPtr(char *&ptr) {
    printf("ptr addr is %x\n", &ptr);
}

int main(int argc, char *argv[])
{
    char *cp = "gagag";
	printf("cp addr: %x\n", cp);
    printf("cp ptr addr %x\n", &cp);

    printPtr(cp);

    return 0;
}
