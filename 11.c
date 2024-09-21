/* 

Name : 11.c
Author : Khushi Patel
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf(" Caught SIGINT: Signal %d\n", signum);
}

int main() {
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);
    printf(" SIGINT ignored. Press Ctrl+C.\n");
    sleep(5);

    sa_default.sa_handler = handle_sigint;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);
    printf(" SIGINT handler restored. Press Ctrl+C.\n");

    while (1) {
        pause();
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 11.c -o 11
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./11
SIGINT ignored. Press Ctrl+C.
^C SIGINT handler restored. Press Ctrl+C.
^C Caught SIGINT: Signal 2



*/
