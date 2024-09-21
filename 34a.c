/* 

Name : 34a.c
Author : Khushi Patel
Description : Write a program to create a concurrent server.
a. use fork

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>

void handle_client(int new_socket) {
    char buffer[1024] = {0};
    char *message = "Hello from server";

    read(new_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent to client\n");

    close(new_socket);
    exit(0);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        if (fork() == 0) { 
            close(server_fd);  
            handle_client(new_socket);
        } else {
            close(new_socket); 
        }
    }

    return 0;
}




/* Output: 




*/
