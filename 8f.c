/* 

Name : 8f.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigvtalrm(int signum) {
    printf("Caught SIGVTALRM: Signal %d\n", signum);
}

int main() {
    struct itimerval timer;
    signal(SIGVTALRM, handle_sigvtalrm);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8f.c -o 8f
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8f
Caught SIGVTALRM: Signal 26



*/
