/*
============================================================================
Name : Question-27
Author : Pratyasa Ray
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 1st sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	/*execl("/bin/ls","ls","Rl",NULL);
	perror("execl");
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
	*/

    char* envp[] = { "PATH=/bin", NULL }; // Set the PATH environment variable to /bin
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execle");
    /*
    char *cmd[]={"ls","-RL",NULL};
    execv("/bin/ls",cmd);
    perror("execv");
    return(EXIT_FAILURE);
   
    char *cmd[]={"ls","-RL",NULL};
    execvp("ls",cmd);
    perror("execvp");
    return(EXIT_FAILURE);
    */
    return 1;
}
