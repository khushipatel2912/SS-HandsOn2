/* 

Name : 30b.c
Author : Khushi Patel
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *data = (char*) shmat(shmid, NULL, SHM_RDONLY); 

    printf("Data in shared memory: %s\n", data);

    strcpy(data, "Attempt to overwrite"); 

    shmdt(data);  

    return 0;
}




/* Output: 


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 30b.c -o 30b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./30b
Data in shared memory: This is shared memory data
Segmentation fault (core dumped)


*/
