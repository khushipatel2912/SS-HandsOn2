/* 

Name : 10a.c
Author : Khushi Patel
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV: Signal %d\n", signum);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);

    int* ptr = NULL;
    *ptr = 42;

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 10a.c -o 10a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./10a
Caught SIGSEGV: Signal 11



*/
