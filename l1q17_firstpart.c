/*
============================================================================
Name : Question-17
Author : Pratyasa Ray
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
        int i,fd;
        struct {
                int train_num;
                int ticket_count;
        } db[3];
        for(i=0; i<3; i++){
                db[i].train_num=i+1;
                db[i].ticket_count=0;
        }
        fd=open("ticket.txt", O_RDWR);
        write(fd,db,sizeof(db));
        close(fd);
}

