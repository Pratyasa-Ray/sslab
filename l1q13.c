/*
============================================================================
Name : Question-13
Author : Pratyasa Ray
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set rfds;
    struct timeval tv;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

 
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input from STDIN for 10 seconds...\n");

    retval = select(1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select");
    } else if (retval) {
        if (FD_ISSET(0, &rfds)) {
            printf("Data is available now!\n");
        }
    } else {
        printf("No data within 10 seconds.\n");
    }

    return 0;
}
