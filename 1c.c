/* 

Name : 1c.c
Author : Khushi Patel
Description : Write a separate program (for each time domain) to set a interval timer in 10 sec and
10 micro second
c. ITIMER_PROF
Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void profile_timer_handler(int signum) {
    static int fire_count = 0;
    printf("Profile timer fired %d times\n", ++fire_count);
}

int main() {
    struct itimerval timer;
    struct sigaction sa;

    sa.sa_handler = profile_timer_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGPROF, &sa, NULL);  

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
    }

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 1c.c -o 1c 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./1c
Profile timer fired 1 times
Profile timer fired 2 times
Profile timer fired 3 times
^C



*/
