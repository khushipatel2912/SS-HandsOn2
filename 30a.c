/* 

Name : 30a.c
Author : Khushi Patel
Description : Write a program to create a shared memory.
a. write some data to the shared memory

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65); 
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 

    char *data = (char*) shmat(shmid, NULL, 0); 

    strcpy(data, "This is shared memory data");  

    printf("Data written to shared memory: %s\n", data);

    shmdt(data);  

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ touch shmfile
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 30a.c -o 30a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./30a
Data written to shared memory: This is shared memory data


*/
