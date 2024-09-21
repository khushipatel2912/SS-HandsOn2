/* 

Name : 14.c
Author : Khushi Patel
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello through the pipe!";
    char read_msg[50];

    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], write_msg, sizeof(write_msg));
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(write_msg));
        printf("Read from pipe: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}




/* Output: 


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 14.c -o 14
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./14
Read from pipe: Hello through the pipe!


*/
