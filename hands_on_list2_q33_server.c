/*
 * ============================================================================
 Name : 33_server.c
 Author : Pratyasa Ray
 Description : Write a simple program to send some data from parent to the child process.
 Date: 7th OCT, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER_SIZE];
    pid_t child_pid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == 0) {
        printf("Listening...\n");
    } else {
        perror("Listening error");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size); // Accept connection

    // Fork a new process to handle client communication
    if ((child_pid = fork()) == 0) {
        close(server_socket); // Close the original socket in the child process

        while (1) {
            // Receive data from the client
            recv(new_socket, buffer, MAX_BUFFER_SIZE, 0);
            if (strcmp(buffer, "exit") == 0) {
                printf("Server exiting...\n");
                break;
            }
            printf("Client: %s", buffer);

            // Send a response to the client
            printf("Server: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            send(new_socket, buffer, strlen(buffer), 0);
        }
        close(new_socket);
    } else {
        wait(NULL);
        close(new_socket);
    }

    return 0;
}

