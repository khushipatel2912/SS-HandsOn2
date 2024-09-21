/* 

Name : 30c.c
Author : Khushi Patel
Description : Write a program to create a shared memory.
c. detach the shared memory

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *data = (char*) shmat(shmid, NULL, 0); 
    printf("Detaching shared memory...\n");

    shmdt(data);  

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 30c.c -o 30c
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./30c
Detaching shared memory...



*/
