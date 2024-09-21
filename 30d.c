/* 

Name : 30d.c
Author : Khushi Patel
Description : Write a program to create a shared memory.
d. remove the shared memory

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory removed successfully.\n");

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 30d.c -o 30d
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./30d
Shared memory removed successfully.

*/
