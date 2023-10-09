/*
 * ============================================================================
 Name : 22.c
 Author : Pratyasa Ray
 Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
 Date: 7th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    const char *fifo_path = "fifoQ21";
    int fd;

    
    fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

  
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);


    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data in the FIFO for up to 10 seconds...\n");

   
    int select_result = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (select_result == -1) {
        perror("select");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (select_result == 0) {
        printf("Timeout reached. No data received.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            char buffer[100];
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
            if (bytes_read == -1) {
                perror("read");
                close(fd);
                exit(EXIT_FAILURE);
            }

            printf("Received data from FIFO: %s", buffer);
        }
    }

    
    close(fd);

    return 0;
}

