/*
============================================================================
Name : Question-6
Author : Pratyasa Ray
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 11th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<stdio.h>
int main()
{
	char buff[20];
	read(0,buff,10); //read 10 bytes from standard input
	write(1,buff,10); //print 10 bytes from the buffer on the screen
}

