/* 

Name : 19d.c
Author : Khushi Patel
Description : Create a FIFO file by
d. mknod system call

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    mknod("myfifo_mknod", S_IFIFO | 0666, 0);
    printf("FIFO created using mknod.\n");
    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./19d
FIFO created using mknod.


*/
