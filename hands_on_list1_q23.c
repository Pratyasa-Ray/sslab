/*
============================================================================
Name : Question-23
Author : Pratyasa Ray
Description : Write a program to create a Zombie state of the running program.
Date:1st sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
	int pid_t,child_pid;
	child_pid=fork();
	if(child_pid>0){
		sleep(10);
	}
	else{
		exit(0);
	}
	return 0;
}

