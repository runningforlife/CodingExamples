#include <stdio.h>

int print_var() {
    static int var = 0;
    
    printf("var valude=%d", var++);
}


int main(void) {

    for (int i = 0; i < 100; ++i) {
        print_var();
    }
}
