/* 

Name : 8c.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
c. SIGFPE

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>

void handle_sigfpe(int signum) {
    printf("Caught SIGFPE (Floating Point Exception): Signal %d\n", signum);
}

int main() {
    signal(SIGFPE, handle_sigfpe);

    int x = 1 / 0;  

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8c.c -o 8c
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8c
Caught SIGFPE (Floating Point Exception): Signal 8



*/
