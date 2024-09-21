/* 

Name : 8b.c
Author : Khushi Patel
Description : Write a separate program using signal system call to catch the following signals.
b. SIGINT

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("Caught SIGINT (Ctrl+C): Signal %d\n", signum);
}

int main() {
    signal(SIGINT, handle_sigint);

    while (1) {
        sleep(1);     
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 8b.c -o 8b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./8b
^CCaught SIGINT (Ctrl+C): Signal 2
^CCaught SIGINT (Ctrl+C): Signal 2


*/
