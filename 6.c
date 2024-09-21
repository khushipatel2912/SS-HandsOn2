/* 

Name : 6.c
Author : Khushi Patel
Description : Write a simple program to create three threads.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread %ld created\n", (long)arg);
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

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 6.c -o 6 -pthread
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./6
Thread 0 created
Thread 1 created
Thread 2 created



*/
