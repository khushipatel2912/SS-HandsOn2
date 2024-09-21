/* 

Name : 20b.c
Author : Khushi Patel
Description : Write two programs so that both can communicate by FIFO -Use one way communication.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int fd = open("myfifo", O_RDONLY);

    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ mkfifo fifo20
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 20a.c -o 20a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 20b.c -o 20b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./20b
Received message: Hello from the writer process!



*/
