/* 

Name : 1a.c
Author : Khushi Patel
Description : Write a separate program (for each time domain) to set a interval timer in 10 sec and
10 micro second
a. ITIMER_REAL
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void timer_handler(int signum) {
    static int count = 0;
    printf("Timer fired %d times\n", ++count);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    sa.sa_handler = &timer_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause();  
    }

    return 0;
}


/* Output: 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 1a.c -o 1a 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./1a
Timer fired 1 times
Timer fired 2 times
Timer fired 3 times
^C
*/
