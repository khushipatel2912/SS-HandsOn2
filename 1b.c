/* 

Name : 1b.c
Author : Khushi Patel
Description : Write a separate program (for each time domain) to set a interval timer in 10 sec and
10 micro second
b. ITIMER_VIRTUAL
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void timer_handler(int signum) {
    static int count = 0;
    printf("Virtual Timer fired %d times\n", ++count);
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    sa.sa_handler = &timer_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGVTALRM, &sa, NULL);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1) {
    }

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 1b.c -o 1b 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./1b
Virtual Timer fired 1 times
Virtual Timer fired 2 times
Virtual Timer fired 3 times
Virtual Timer fired 4 times
^C


*/
