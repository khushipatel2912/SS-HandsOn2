/* 

Name : 16.c
Author : Khushi Patel
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);  
    pipe(pipe2);  

    if (fork() == 0) {
    
        close(pipe1[1]);  
        close(pipe2[0]); 

        char parent_to_child_msg[50];
        read(pipe1[0], parent_to_child_msg, sizeof(parent_to_child_msg)); 
        printf("Child received: %s\n", parent_to_child_msg);

        char child_to_parent_msg[] = "Child to Parent Response!";
        write(pipe2[1], child_to_parent_msg, sizeof(child_to_parent_msg)); 

        close(pipe1[0]); 
        close(pipe2[1]); 
    } else {
    
        close(pipe1[0]); 
        close(pipe2[1]); 

        char parent_msg[] = "Parent to Child Message!";
        write(pipe1[1], parent_msg, sizeof(parent_msg));

        char child_msg[50];
        read(pipe2[0], child_msg, sizeof(child_msg));  
        printf("Parent received: %s\n", child_msg);

        close(pipe1[1]); 
        close(pipe2[0]);
    }

    return 0;
}




/* Output: 


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 16.c -o 16
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./16
Child received: Parent to Child Message!
Parent received: Child to Parent Response!


*/
