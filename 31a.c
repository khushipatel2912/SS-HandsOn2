/* 

Name : 31a.c
Author : Khushi Patel
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    sem_t *binary_semaphore;

    binary_semaphore = sem_open("/binary_semaphore", O_CREAT, 0666, 1);

    if (binary_semaphore == SEM_FAILED) {
        perror("Failed to create binary semaphore");
        return 1;
    }

    printf("Binary semaphore created and initialized to 1.\n");

    sem_close(binary_semaphore);
    sem_unlink("/binary_semaphore"); 

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 31a.c -o 31a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./31a
Binary semaphore created and initialized to 1.

*/
