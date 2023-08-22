#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd1=creat("t1",0744);
	int fd2=creat("t2",0744);
        int fd3=creat("t3",0744);
	int fd4=creat("t4",0744);
	while(1);
}
