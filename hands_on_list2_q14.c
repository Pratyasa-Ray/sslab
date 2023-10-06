#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int a[2];
	char buff[20];
	if(pipe(a) ==-1){
		printf("error creating pipe");
		exit(1);
	}
	write(a[1],"abc",5);
	printf("\n");

	read(a[0],buff,5);

	printf("%s \n",buff);
}



