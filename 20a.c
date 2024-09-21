/* 

Name : 20a.c
Author : Khushi Patel
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char message[] = "Hello from the writer process!";
    int fd = open("myfifo", O_WRONLY);

    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    write(fd, message, sizeof(message));
    close(fd);

    return 0;
}




/* Output: 




*/
