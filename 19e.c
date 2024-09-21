/* 

Name : 19e.c
Author : Khushi Patel
Description : Create a FIFO file by
e. mkfifo library function
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/stat.h>

int main() {
    mkfifo("myfifo_mkfifo", 0666);
    printf("FIFO created using mkfifo.\n");
    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./19e
FIFO created using mkfifo.



*/
