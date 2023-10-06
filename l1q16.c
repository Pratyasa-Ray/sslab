/*
============================================================================
Name : Question-16
Author : Pratyasa Ray
Description : Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* filename = "lock_test.txt";
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Set a write lock
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;  // TILL THE END OF FILE

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error setting write lock");
        return 1;
    }

    printf("Write lock acquired. Press Enter to release lock.\n");
    getchar();

    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error releasing lock");
        return 1;
    }

    close(fd);

    return 0;
}
