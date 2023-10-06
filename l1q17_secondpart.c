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
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
struct{
        int train_num;
        int ticket_count;
}db;
int main(){
        int fd,input;
        fd=open("ticket.txt",O_RDWR);
        printf("Select train number(1,2,3) : \n");
        scanf("%d",&input);
        struct flock lock;
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=(input-1)*sizeof(db);
        lock.l_len=sizeof(db);
        lock.l_pid=getpid();

        lseek(fd,(input-1)*sizeof(db), SEEK_SET);
        read(fd,&db,sizeof(db));
        printf("before entering the critical section \n");

        fcntl(fd,F_SETLKW,&lock);
        printf("ticket number: %d \n",db.ticket_count);
        db.ticket_count++;
        lseek(fd,-1*sizeof(db),SEEK_CUR);
        write(fd,&db,sizeof(db));// updating db with new ticket number
        printf("to book ticket, press enter: \n");
        getchar();
        getchar();
        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK,&lock);
        printf("Booked \n");
}
