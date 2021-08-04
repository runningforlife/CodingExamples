#include <stdio.h>
#include <stdlib.h>

int main(void) {

   int version = 0x0c;
   int str_version = strtol("0x0c", NULL, 0);
   if (version >= str_version) {
      printf("%d is larger than %d\n", version, str_version); 
   } else {
      printf("%d is smaller than %d\n", version, str_version);
   }

}
