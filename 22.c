/* 

Name : 22.c
Author : Khushi Patel
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    char buffer[100];
    int fd = open("fifo22", O_RDONLY | O_NONBLOCK);
    
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int result = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select error");
    } else if (result == 0) {
        printf("No data written to the FIFO within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            read(fd, buffer, sizeof(buffer));
            printf("Received data: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}




/* Output: 


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 22.c -o 22
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./22
Received data: Hello through FIFO


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./22
No data written to the FIFO within 10 seconds.




*/
