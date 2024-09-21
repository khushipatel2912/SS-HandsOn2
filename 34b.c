/* 

Name : 34b.c
Author : Khushi Patel
Description : Write a program to create a concurrent server.
b. use pthread_create

Date: 20th Sep, 2024.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

void* handle_client(void* socket_desc) {
    int new_socket = *(int*)socket_desc;
    char buffer[1024] = {0};
    char *message = "Hello from server";

    read(new_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent to client\n");

    close(new_socket);
    free(socket_desc);  // Free memory allocated for socket descriptor
    return NULL;
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

        pthread_t thread_id;
        int *socket_desc = malloc(sizeof(int));
        *socket_desc = new_socket;

        if (pthread_create(&thread_id, NULL, handle_client, (void*)socket_desc) < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }

        printf("Handler assigned\n");
    }

    return 0;
}




/* Output: 

khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 34a.c -o 34a
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ gcc 34b.c -o 34b
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./33b
Connection Failed: Connection refused
khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./34a
Message from client: Hello from Client 1

Hello message sent to client
Message from client: Hello from Client 2

Hello message sent to client


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./33b
Enter message to send to server: Hello from Client 1
Message sent from client: Hello from Client 1
Message from server: Hello from server


khushi@khushi-HP-Pavilion-Laptop-14-dv0xxx:~/my-repo/HandsOn2$ ./33b
Enter message to send to server: Hello from Client 2
Message sent from client: Hello from Client 2
Message from server: Hello from server

*/
