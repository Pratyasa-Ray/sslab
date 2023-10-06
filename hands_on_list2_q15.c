#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	int fd[2];
	int childID = 0;
	pipe(fd);
	if (fork() != 0) {
		close(fd[0]);
		childID = 1;
		write(fd[1], &childID, sizeof(childID));
		printf("Parent(%d) send childID: %d\n", getpid(), childID);
		close(fd[1]);
	} else {
		close(fd[1]);
		read(fd[0], &childID, sizeof(childID));
		printf("Child(%d) received childID: %d\n", getpid(), childID);
		close(fd[0]);
	}
	return 0;
}
