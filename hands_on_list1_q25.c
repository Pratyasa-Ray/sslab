/*
============================================================================
Name : Question-25
Author : Pratyasa Ray
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 1st sept, 2023.
============================================================================
*/
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int cpid1=fork();
	int cpid2=fork();

	if(cpid1!=0 && cpid2!=0){
		int waitPID=0;
		int status;
		printf("this is the parent process waiting for the process id: %d \n",cpid2);
		while(waitPID==0){
			waitPID=waitpid(cpid2,&status,WNOHANG);
		}
		printf("\n parent process waited for child,the return value of waitpid(): %d \n",waitPID);
		printf("the exit code of terminated child: %d \n",WEXITSTATUS(status));
		exit(1);
		}
	else if(cpid1==0 && cpid2!=0){
		printf("\nchild 1: process id : %d , my exit code is 1\n",getpid());
		exit(1);
	}
	else if(cpid1!=0 && cpid2==0){
		printf("\nchild 2:process id: %d , my exit code is 2\n",getpid());
		exit(2);
	}
	else{
		printf("\n child 3: process id: %d , my exit code is 3\n",getpid());
		exit(3);
	}
	return 0;
}
