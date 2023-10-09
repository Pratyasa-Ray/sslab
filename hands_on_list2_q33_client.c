/*
 * ============================================================================
 Name : 33_client.c
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
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("172.16.144.120"); // Server IP address

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    while (1) {
        // Send data to the server
        printf("Client: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive a response from the server
        recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        printf("Server: %s", buffer);

        // Check for the "exit" command to terminate the client
        if (strcmp(buffer, "exit") == 0) {
            printf("Client exiting...\n");
            break;
        }
    }

    close(client_socket);

    return 0;
}

