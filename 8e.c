/* 

Name : 8e.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM (setitimer): Signal %d\n", signum);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause(); 
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8e.c -o 8e
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8e
Caught SIGALRM (setitimer): Signal 14
Caught SIGALRM (setitimer): Signal 14


*/
