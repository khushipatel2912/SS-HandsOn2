/* 

Name : 8g.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigprof(int signum) {
    printf("Caught SIGPROF: Signal %d\n", signum);
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handle_sigprof);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
    }

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8g.c -o 8g
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8g
Caught SIGPROF: Signal 27
Caught SIGPROF: Signal 27


*/
