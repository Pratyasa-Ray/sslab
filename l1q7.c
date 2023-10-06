/*
============================================================================
Name : Question-7
Author : Pratyasa Ray
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 11th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[]){
        if(argc!=3){
                printf("not valid args");
        }
        int fd_read=open(argv[1],O_RDONLY);
        int fd_write=open(argv[2],O_WRONLY |O_CREAT);
        if(fd_read==-1 || fd_write ==-1){
                printf("\nCould not open file.");
        }
        while(1){
                char buff;
                int char_read=read(fd_read,&buff,1);
                if(char_read==0){
                        break;
                }
                int char_write=write(fd_write,&buff,1);
        }
        int fd_read_close=close(fd_read);
        int fd_write_close=close(fd_write);
        if(fd_read_close==-1 || fd_write_close==-1){
                printf("files could not be closed");
        }
        return 0;
}
