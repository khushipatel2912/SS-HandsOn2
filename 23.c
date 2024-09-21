/* 

Name : 23.c
Author : Khushi Patel
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    long open_files_limit = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of files that can be opened in a process: %ld\n", open_files_limit);

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("Error creating pipe");
        return 1;
    }

    printf("Pipe created. Using default pipe buffer size of 65536 bytes (on most Linux systems).\n");

    close(pipe_fds[0]);
    close(pipe_fds[1]);

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 23.c -o 23
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./23
Maximum number of files that can be opened in a process: 1024
Pipe created. Using default pipe buffer size of 65536 bytes (on most Linux systems).


*/
