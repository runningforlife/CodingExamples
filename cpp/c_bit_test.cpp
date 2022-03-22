/* struct bit field examples */
#include<iostream>
#include<string.h>

struct bit_map {
   int ch;
   unsigned int bc:1;
   unsigned int bd:1;
};

int main(void)
{
     struct bit_map bm;
	 memset(&bm, 0, sizeof(bm));

     bm.ch = 'c';
     bm.bc = 1;
     bm.bd = 0;

     std::cout << "size of bit map is " << sizeof(bm) << std::endl;
	 std::cout << "bc=" << bm.bc << ",bd=" << bm.bd << std::endl;
}

