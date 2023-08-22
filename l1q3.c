#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
int main(){
	int fd=creat("temp1",0744);
	if(fd<0){
		perror("failed");
		exit(1);
	}
	printf("file created:%d ",fd);
}
