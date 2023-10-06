/*
============================================================================
Name : Question-15
Author : Pratyasa Ray
Description : Write a program to display the environmental variable of the user (use environ).
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main() {
    char** env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
