/* 

Name : 10b.c
Author : Khushi Patel
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf(" Caught SIGINT: Signal %d\n", signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 10b.c -o 10b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./10b
^C Caught SIGINT: Signal 2
^C Caught SIGINT: Signal 2

*/
