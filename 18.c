/* 

Name : 18.c
Author : Khushi Patel
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

Date: 20th Sep, 2024.

*/




#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1); 
    pipe(fd2);  

    if (fork() == 0) {
        close(fd1[0]);
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[1]);
        execlp("ls", "ls", "-l", NULL);
    } else if (fork() == 0) {
        close(fd1[1]);
        dup2(fd1[0], STDIN_FILENO);
        close(fd1[0]);
        close(fd2[0]);
        dup2(fd2[1], STDOUT_FILENO);
        close(fd2[1]);
        execlp("grep", "grep", "^d", NULL);
    } else {
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[1]);
        dup2(fd2[0], STDIN_FILENO);
        close(fd2[0]);
        execlp("wc", "wc", "-l", NULL);
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ mkdir dir1 
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ mkdir dir2
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 18.c -o 18
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./18
2


*/
