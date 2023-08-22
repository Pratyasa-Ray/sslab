#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd=open("t1",O_RDWR|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
	if(fd== -1)
		errExit("open");
	ssize_t write(fd,"l1q8",10);
	off_t lseek(fd,10,SEEK_END);
	ssize_t write(fd,"l1q8",10);
	int curr=lseek(fd,0,SEEK_CUR);
	printf("the current offset value: %d \n",curr);



