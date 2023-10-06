/*
============================================================================
Name : Question-4
Author : Pratyasa Ray
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 11th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
int main(){
	int fd=open("temp1.txt",O_RDWR|O_EXCL,0644);
	if((fd==-1) && (EEXIST==errno)){
		fd=open("temp1.txt",O_RDWR);
	}
}
	
