/* 

Name : 17b.c
Author : Khushi Patel
Description : Write a program to execute ls -l | wc.
b. use dup2

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }

    return 0;
}






/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./17b
     90     803    4510


*/
