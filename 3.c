/* 

Name : 3.c
Author : Khushi Patel
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/resource.h>

void set_stack_size_limit(rlim_t new_limit) {
    struct rlimit limit;

    if (getrlimit(RLIMIT_STACK, &limit) == 0) {
        printf("Current stack size limit: \n");
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", (long)limit.rlim_max);

        limit.rlim_cur = new_limit;  
        if (setrlimit(RLIMIT_STACK, &limit) == 0) {
            printf("Stack size limit set to: %ld\n\n", (long)new_limit);
        } else {
            perror("setrlimit"); 
        }
    } else {
        perror("getrlimit");  
    }
}

int main() {

    set_stack_size_limit(16 * 1024 * 1024);  

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 3.c -o 3
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./3
Current stack size limit: 
  Soft limit: 8388608
  Hard limit: -1

Stack size limit set to: 16777216




*/
