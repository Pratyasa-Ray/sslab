/*
============================================================================
Name : Question-21
Author : Pratyasa Ray
Description : Write a program, call fork and print the parent and child process id.
Date: 1st sept, 2023.
============================================================================
*/
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
	pid_t pid=fork();

	if(pid==0){
		printf("child's parent  process id: %d \n child's process id: %d \n",getppid(),getpid());
		exit(0);
	}
	else if(pid>0){
		printf("parent process id: %d \n",getpid());
		printf("waiting for child process to finish....");
		wait(NULL);
		printf("child process finished");
	}
	else{
		printf("unable to create child process.\n");
	}
	return 0;
}
