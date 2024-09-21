/* 

Name : 8a.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h> 

void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV (Segmentation Fault): Signal %d\n", signum);
    exit(1);  
}

int main() {
    signal(SIGSEGV, handle_sigsegv);

    int* ptr = NULL;
    *ptr = 42;

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8a.c -o 8a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8a
Caught SIGSEGV (Segmentation Fault): Signal 11




*/
