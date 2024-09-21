/* 

Name : 4.c
Author : Khushi Patel
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>  

int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();

    printf("Time taken for 100 getppid() calls: %llu clock cycles\n", end - start);

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 4.c -o 4
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./4
Time taken for 100 getppid() calls: 65254 clock cycles



*/
