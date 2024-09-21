/* 

Name : 26b.c
Author : Khushi Patel
Description : Write a program to send messages to the message queue. Check $ipcs -q

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

    printf("Message received from queue: %s\n", message.msg_text);

    return 0;
}





/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./26a
Message sent to queue: Hello, this is a message.
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./26b
Message received from queue: Hello, this is a message.
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41050798 0          khushi     666        0            0           





*/
