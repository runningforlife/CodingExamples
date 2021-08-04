#include<iostream>


int do_while_test() {
   int rc = -1;
   do {
      int val = 1;
      switch (val) {
         case 1:
            if (val%2 == 1) {
               ++val;
               continue;
            }
            std::cout << "val is 1" << std::endl;
            break;
         default:
            break;
      }
      std::cout << "while end" << std::endl;
      rc = val;
   } while(0);

   return rc;
}


int main(void)
{
   int rs = do_while_test();

   std::cout << "test result is " << rs << std::endl;
}
