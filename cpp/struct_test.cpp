#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t magic1;//(0x78E5D4C2)
    uint32_t magic2;//(0x54F7D60E)

    uint32_t boot_partition;//1-A partition, 2-B partition;

    char current_kernel_partition[16];//include the string ending
    char current_rootfs_partition[16];
    char current_modem_partition[16];

    char burning_kernel_partition[16];
    char burning_rootfs_partition[16];
    char burning_modem_partition[16];

    uint32_t times_of_boot_failed;
    uint32_t boot_reason;//0-normal; 1-flash error; 2-boot failed;

    uint32_t check_sum_a;
    uint32_t check_sum_b;
} quec_backup_info_type_t;

int main(void) {


   int len = (int)(&(((quec_backup_info_type_t *)0)->check_sum_a));
   int sum_len = sizeof(quec_backup_info_type_t) - 2 * sizeof(uint32_t);
   
   printf("value of len is %d %d\n", len, sum_len);
}
