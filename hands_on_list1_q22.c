/*
============================================================================
Name : Question-22
Author : Pratyasa Ray
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 1st sept, 2023.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	fd=open("forkbuffer.txt",O_RDWR);
	if(fd<0){
		printf("error opening file");
	}
	pid_t pid=fork();
	char child_buffer[10];
	char parent_buffer[10];
	if(pid==0){
		printf("child's parent process id: %d \n child's process id: %d \n",getppid(),getpid());
		printf("enter the contents as child: \n");
		scanf("%[^\n]",child_buffer);
		write(fd,child_buffer,10);
		exit(0);
	}
	if(pid>0){
		printf("parent process id: %d \n",getpid());
		printf("waiting for child process to write...\n");
		wait(NULL);
		printf("write the contents for parent : \n");
		scanf("%[^\n]",parent_buffer);
		write(fd,parent_buffer,10);
		exit(0);
	}
	else{
		printf("unable to create child process\n");
	}
	return 0;
}

	

