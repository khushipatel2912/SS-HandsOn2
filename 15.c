/* 

Name : 15.c
Author : Khushi Patel
Description : Write a simple program to send some data from parent to the child process.

Date: 20th Sep, 2024.

*/



#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        char child_msg[50];
        read(fd[0], child_msg, sizeof(child_msg));
        printf("Child received: %s\n", child_msg);
        close(fd[0]);
    } else {
        close(fd[0]);
        char parent_msg[] = "Message from parent to child!";
        write(fd[1], parent_msg, sizeof(parent_msg));
        close(fd[1]);
    }

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 15.c -o 15
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./15
Child received: Message from parent to child!



*/
