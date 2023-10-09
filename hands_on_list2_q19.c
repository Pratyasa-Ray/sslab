/*
 * ============================================================================
 Name : 19.c
 Author : Pratyasa Ray
 Description : Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
 Date: 7th OCT, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *fifo_path = "myfifo";
    int result;

    result = mkfifo(fifo_path, 0666); 

    if (result == 0) {
        printf("FIFO file '%s' created successfully.\n", fifo_path);
    } else {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    return 0;
}

