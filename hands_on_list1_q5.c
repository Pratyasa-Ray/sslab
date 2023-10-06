/*
============================================================================
Name : Question-5
Author : Pratyasa Ray
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 11th Aug, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main (void){
        int fd1, fd2, fd3, fd4, fd5;
        fd1=creat("file1", 0744);
        fd2=creat("file2", 0744);
        fd3=creat("file3", 0744);
        fd4=creat("file4", 0744);
        fd5=creat("file5", 0744);

        for(;;);
}
