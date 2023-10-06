/*
============================================================================
Name : Question-1
Author : Pratyasa Ray
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 11th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
        /*int l =link("Q1Handsonlink.txt","Q1Handsonlink_hardlink.txt");

        int sl= symlink("Q1Handsonlink.txt","Q1Handsonlink_softlink.txt");


        if(l==0){
                printf("\nHard link created successfully.");
        }
        else{
                printf("\nHard Link not created");
        }

        if(sl==0){
                printf("\nSoft Link created successfully");
        }
        else{
                printf("\nSoft Link not created.");
        }*/
        int f=mknod("Q1Handsonlink",S_IFIFO,0);
        if(f<0) perror("Failed");

        return 0;
}
