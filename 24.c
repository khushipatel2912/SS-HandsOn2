/* 

Name : 24.c
Author : Khushi Patel
Description : Write a program to create a message queue and print the key and message queue id.

Date: 20th Sep, 2024.

*/



#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

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

    printf("Message Queue created successfully.\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}



/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ touch progfile
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 24.c -o 24
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./24
Message Queue created successfully.
Key: 1090848664
Message Queue ID: 0



*/
