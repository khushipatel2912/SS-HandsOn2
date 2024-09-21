/* 

Name : 7.c
Author : Khushi Patel
Description : Write a simple program to print the created thread ids.

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread %ld has ID %lu\n", (long)arg, pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 7.c -o 7 -pthread
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./7 
Thread 0 has ID 139814672266944
Thread 2 has ID 139814655481536
Thread 1 has ID 139814663874240



*/
