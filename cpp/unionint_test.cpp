#include<stdio.h>
#include<stdint.h>

union mark {
     uint32_t value;
     struct {
          uint16_t id     : 16;
          bool selected   :  1;
          uint8_t perm    :  8;
     };

     mark() : value(0) {}
};


int main() {
    mark markV;
    markV.id = 64;
    markV.selected = false;

    printf("mark value is %d\n", markV.value);

    return 0;
}


