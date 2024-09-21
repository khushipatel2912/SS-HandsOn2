/* 

Name : 32d.c
Author : Khushi Patel
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <semaphore.h>

int main() {
    sem_t semaphore;

    sem_init(&semaphore, 0, 1);  

    sem_destroy(&semaphore);  
    printf("Semaphore destroyed.\n");

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./32d
Semaphore destroyed.


*/
