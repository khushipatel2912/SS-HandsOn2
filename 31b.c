/* 

Name : 31b.c
Author : Khushi Patel
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    sem_t *counting_semaphore;

    counting_semaphore = sem_open("/counting_semaphore", O_CREAT, 0666, 3);

    if (counting_semaphore == SEM_FAILED) {
        perror("Failed to create counting semaphore");
        return 1;
    }

    printf("Counting semaphore created and initialized to 3.\n");

    sem_close(counting_semaphore);
    sem_unlink("/counting_semaphore");

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 31b.c -o 31b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./31b
Counting semaphore created and initialized to 3.


*/
