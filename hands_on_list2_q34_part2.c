/*
 * ============================================================================
 Name : 34_part2.c
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
#include <pthread.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

void *handle_client(void *arg);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    pthread_t tid;

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

    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);

        // Create a new thread to handle the client
        if (pthread_create(&tid, NULL, handle_client, (void*)&client_socket) != 0) {
            perror("Thread creation error");
            close(client_socket);
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *((int*)arg);
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;

    while (1) {
        // Receive data from the client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        // Null-terminate the received data
        buffer[bytes_received] = '\0';

        // Process the received data (e.g., print it)
        printf("Client: %s", buffer);

        // Send a response back to the client
        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        // Check for the "exit" command to terminate the client
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Client disconnected.\n");
            break;
        }
    }

    close(client_socket);
    pthread_exit(NULL);
}

