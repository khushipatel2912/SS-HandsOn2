/* 

Name : 28.c
Author : Khushi Patel
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msgctl(msgid, IPC_STAT, &buf); 

    buf.msg_perm.mode = 0600;  

    msgctl(msgid, IPC_SET, &buf);  

    printf("Message queue permissions changed.\n");

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 28.c -o 28
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./28
Message queue permissions changed.



*/
