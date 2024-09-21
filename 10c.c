/* 

Name : 10c.c
Author : Khushi Patel
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE: Signal %d\n", signum);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL);

    int x = 1 / 0;

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 10c.c -o 10c
10c.c: In function ‘main’:
10c.c:29:15: warning: division by zero [-Wdiv-by-zero]
   29 |     int x = 1 / 0;
      |               ^
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./10c
Caught SIGFPE: Signal 8

*/
