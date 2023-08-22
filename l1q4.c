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
	
