/*
============================================================================
Name : Question-8
Author : Pratyasa Ray
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 11th Aug, 2023.
============================================================================
*/
#include <stdio.h>

int main() {
    char filename[100];
    FILE *file;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File '%s' not found.\n", filename);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);

    return 0;}
