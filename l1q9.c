#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int inode,no_of_hardlink;
	int fd=open("t1",O_RDWR);
	if(fd<0){
		printf("error opening the file");
	}
	struct stat file_stat;
	int result=fstat(fd,&file_stat);
	if(result<0){
	printf("error getting file stat");
	}
	inode=file_stat.st_ino;
	printf("node of the file: %d \n",inode);
	no_of_hardlink=file_stat.st_nlink;
	printf("number of hard links to the file: %d  \n",no_of_hardlink);
	int uid=file_stat.st_uid;
	printf("user ID of the file owner: %d \n",uid);
	int gid=file_stat.st_gid;
	printf("group ID of the file owner: %d \n",gid);
	int size=file_stat.st_size;
	printf("total size of the file: %d \n",size);
	int blocksize=file_stat.st_blksize;
	printf("blocksize: %d \n",blocksize);
	int no_of_blocks=file_stat.st_blocks;
	printf("no.of blocks: %d \n",no_of_blocks);
	int last_time_access=file_stat.st_atime;
	printf("time of last access: %d \n",last_time_access);
	int last_time_modified=file_stat.st_mtime;
	printf("time of last file modification: %d \n",last_time_modified);
	int last_time_statuschange=file_stat.st_ctime;
	printf("time of last status change: %d \n",last_time_statuschange);
}

