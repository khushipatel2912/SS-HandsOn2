/* 

Name : 13b.c
Author : Khushi Patel
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Enter the PID of the process to send SIGSTOP to: ");
    scanf("%d", &pid);

    kill(pid, SIGSTOP);
    printf("Sent SIGSTOP to process %d\n", pid);

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 13b.c -o 13b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./13b
Enter the PID of the process to send SIGSTOP to: 15697
Sent SIGSTOP to process 15697



*/
