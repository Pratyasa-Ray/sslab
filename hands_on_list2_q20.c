/*
 * ============================================================================
 Name : 20.c
 Author : Pratyasa Ray
 Description : Write two programs so that both can communicate by FIFO -Use one way communication.
 Date: 7th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    const char *fifo_path = "fifo2";
    int fd;
    //char buffer[100];


    fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

 //for writtig
    char message[] = "Hello from Writer Program!";
    if (write(fd, message, strlen(message) + 1) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Writer: Wrote data to the FIFO: %s\n", message);

 /*
  //for reading
  ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
*/
    close(fd);

    return 0;
}

