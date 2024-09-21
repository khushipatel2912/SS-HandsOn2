/* 

Name : 32c.c
Author : Khushi Patel
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* access_resource(void* arg) {
    sem_wait(&semaphore);  
    printf("Resource accessed by thread %ld\n", (long)arg);
    sem_post(&semaphore); 
    return NULL;
}

int main() {
    pthread_t threads[5];

    sem_init(&semaphore, 0, 2);  

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, access_resource, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); 

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./32c
Resource accessed by thread 0
Resource accessed by thread 3
Resource accessed by thread 2
Resource accessed by thread 4
Resource accessed by thread 1


*/
