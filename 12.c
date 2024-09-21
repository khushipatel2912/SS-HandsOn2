/* 

Name : 12.c
Author : Khushi Patel
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent process (PID: %d)\n", getpid());
        sleep(10); 
    } else if (pid == 0) {
        sleep(1); 
        printf("Child process (PID: %d)\n", getpid());
        kill(getppid(), SIGKILL); 
        printf("Parent process killed. Child becomes an orphan.\n");
        sleep(10);  
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 12.c -o 12
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./12
Parent process (PID: 15581)
Child process (PID: 15582)
Parent process killed. Child becomes an orphan.
Killed

*/
