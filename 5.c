/* 

Name : 5.c
Author : Khushi Patel
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Max argument length: %ld\n", sysconf(_SC_ARG_MAX));

    printf("Max processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));

    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));

    printf("Max number of open files: %ld\n", sysconf(_SC_OPEN_MAX));

    printf("Page size: %ld bytes\n", sysconf(_SC_PAGESIZE));

    printf("Total number of pages: %ld\n", sysconf(_SC_PHYS_PAGES));

    printf("Available pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 5.c -o 5
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./5
Max argument length: 2097152
Max processes per user ID: 62707
Clock ticks per second: 100
Max number of open files: 1024
Page size: 4096 bytes
Total number of pages: 4032051
Available pages: 2981309

*/
