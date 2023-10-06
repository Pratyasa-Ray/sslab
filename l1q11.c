/*
============================================================================
Name : Question-11
Author : Pratyasa Ray
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
    const char* filename = "t1.txt"; 
    int fd_original, fd_dup, fd_dup2, fd_fcntl;

    fd_original = open("t1", O_WRONLY | O_APPEND);
    if (fd_original == -1) {
        perror("Error opening file");
        return 1;
    }
    fd_dup = dup(fd_original);
    fd_dup2 = dup2(fd_original, 5);
    fd_fcntl = fcntl(fd_original, F_DUPFD, 0);

    const char* data = "Appended using original descriptor.\n";
    write(fd_original, data, strlen(data));

    const char* data_dup = "Appended using dup descriptor.\n";
    write(fd_dup, data_dup, strlen(data_dup));

    const char* data_dup2 = "Appended using dup2 descriptor.\n";
    write(fd_dup2, data_dup2, strlen(data_dup2));

    const char* data_fcntl = "Appended using fcntl descriptor.\n";
    write(fd_fcntl, data_fcntl, strlen(data_fcntl));

    close(fd_original);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
