/* 

Name : 29.c
Author : Khushi Patel
Description : Write a program to remove the message queue.

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    
    msgctl(msgid, IPC_RMID, NULL);  
    printf("Message queue removed successfully.\n");

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 29.c -o 29
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./29
Message queue removed successfully.



*/
