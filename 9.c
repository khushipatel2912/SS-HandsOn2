/* 

Name : 9.c
Author : Khushi Patel
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf(" Caught SIGINT: Signal %d\n", signum);
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf(" SIGINT ignored. Press Ctrl+C.\n");
    sleep(5);

    signal(SIGINT, handle_sigint);
    printf(" SIGINT handler restored. Press Ctrl+C.\n");

    while (1) {
        pause();
    }

    return 0;
}




/* Output: 


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 9.c -o 9
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./9
SIGINT ignored. Press Ctrl+C.
^C SIGINT handler restored. Press Ctrl+C.
^C Caught SIGINT: Signal 2


*/
