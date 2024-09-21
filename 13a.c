/* 

Name : 13a.c
Author : Khushi Patel
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Waiting for SIGSTOP... (PID: %d)\n", getpid());
    while (1) {
        pause();
    }
    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./13a
Waiting for SIGSTOP... (PID: 15697)
Terminated


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ kill -CONT 15697
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ kill -TERM 15697



*/
