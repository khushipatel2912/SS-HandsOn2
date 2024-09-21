/* 

Name : 21a.c
Author : Khushi Patel
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO1 "fifo21a"
#define FIFO2 "fifo21b"

int main() {
    char buffer[1024];
    int fd_write, fd_read;
    
    fd_write = open(FIFO1, O_WRONLY);
    fd_read = open(FIFO2, O_RDONLY);

    if (fd_write == -1 || fd_read == -1) {
        perror("Error opening FIFO");
        exit(1);
    }

    while (1) {
        printf("You: ");
        fgets(buffer, sizeof(buffer), stdin);

        write(fd_write, buffer, strlen(buffer) + 1);

        if (read(fd_read, buffer, sizeof(buffer)) > 0) {
            printf("Received: %s\n", buffer);
        }
    }

    close(fd_write);
    close(fd_read);
    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./21a
You: Hi  
Received: What's up?

You:     



khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./21b
Received: Hi

You: What's up?



*/
