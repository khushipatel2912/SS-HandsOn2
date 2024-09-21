/* 

Name : 2.c
Author : Khushi Patel
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <sys/resource.h>

void print_limit(int resource, const char* resource_name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%s: \n", resource_name);
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");  
    }
}

int main() {
   
    print_limit(RLIMIT_CPU, "CPU time");

    print_limit(RLIMIT_FSIZE, "Maximum file size");

    print_limit(RLIMIT_STACK, "Stack size");

    print_limit(RLIMIT_AS, "Address space size");

    print_limit(RLIMIT_NOFILE, "Number of open file descriptors");

    print_limit(RLIMIT_NPROC, "Number of processes");

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 2.c -o 2
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./2
CPU time: 
  Soft limit: -1
  Hard limit: -1

Maximum file size: 
  Soft limit: -1
  Hard limit: -1

Stack size: 
  Soft limit: 8388608
  Hard limit: -1

Address space size: 
  Soft limit: -1
  Hard limit: -1

Number of open file descriptors: 
  Soft limit: 1024
  Hard limit: 1048576

Number of processes: 
  Soft limit: 62707
  Hard limit: 62707


*/
