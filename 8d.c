/* 

Name : 8d.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigalrm(int signum) {
    printf("Caught SIGALRM: Signal %d\n", signum);
}

int main() {
    signal(SIGALRM, handle_sigalrm);
    alarm(2); 

    while (1) {
        pause(); 
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8d.c -o 8d
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8d
Caught SIGALRM: Signal 14
^C

*/
