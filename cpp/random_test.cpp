#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {


    int i = 0;
 
    while (i++ < 10) {
        int r = random();
        uint8_t byte = r & 0xFF;
        printf("got random char %c\n", byte);
    }
}
