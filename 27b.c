/* 

Name : 27b.c
Author : Khushi Patel
Description : Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

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

    // Receiving message with IPC_NOWAIT flag (non-blocking mode)
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        perror("msgrcv error");
        if (errno == ENOMSG) {
            printf("No message available in the queue\n");
        }
    } else {
        printf("Message received: %s\n", message.msg_text);
    }

    return 0;
}

  



/* Output: 




*/
