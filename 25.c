/* 

Name : 25.c
Author : Khushi Patel
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

Date: 20th Sep, 2024.

*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok error");
        return 1;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget error");
        return 1;
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl error");
        return 1;
    }

    printf("Message Queue Information:\n");
    printf("Access Permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&buf.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&buf.msg_rtime));
    printf("Time of Last Change in Message Queue: %s", ctime(&buf.msg_ctime));
    printf("Size of Queue (bytes): %lu\n", buf.__msg_cbytes);
    printf("Number of Messages in Queue: %lu\n", buf.msg_qnum);
    printf("Maximum Number of Bytes Allowed in Queue: %lu\n", buf.msg_qbytes);
    printf("PID of Last Message Sent: %d\n", buf.msg_lspid);
    printf("PID of Last Message Received: %d\n", buf.msg_lrpid);

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 25.c -o 25
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./25
Message Queue Information:
Access Permissions: 666
UID: 1000
GID: 1000
Time of Last Message Sent: Thu Jan  1 05:30:00 1970
Time of Last Message Received: Thu Jan  1 05:30:00 1970
Time of Last Change in Message Queue: Fri Sep 20 23:50:52 2024
Size of Queue (bytes): 0
Number of Messages in Queue: 0
Maximum Number of Bytes Allowed in Queue: 16384
PID of Last Message Sent: 0
PID of Last Message Received: 0



*/
