#include<iostream>
#include<string.h>

struct bit_map {
   int ch;
   int bc:1;
   int bd:1;
};

int main(void)
{
     struct bit_map bm;
     bm.ch = 'c';
     bm.bc = 1;
     bm.bd = 2;

     std::cout << "size of bit map is " << sizeof(bm) << std::endl;
}

