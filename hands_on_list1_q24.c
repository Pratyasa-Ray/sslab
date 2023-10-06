/*
============================================================================
Name : Question-24
Author : Pratyasa Ray
Description : Write a program to create an orphan process.
Date: 1st sept, 2023.
============================================================================
*/
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		sleep(10); //child process is put to sleep and in this time the parent process executes and terminates
	        printf("this is the child process having id: %d\n",getpid());
		printf("my parent's id is: %d\n",getppid());
	}	
	else{
		printf("this is the parent process: %d\n",getpid());
		printf("my child process id id: %d \n",pid);
	}
	return 0;
}
