/*
============================================================================
Name : Question-12
Author : Pratyasa Ray
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
int main(){
	int fd=open("t1",O_RDONLY);
	int flags,accessMode;
	flags=fcntl(fd,F_GETFL);
	if(flags==-1)
		exit(1);
	printf("opening mode %d \n",flags);
}

