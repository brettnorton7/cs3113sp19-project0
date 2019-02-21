#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * main method of the program
 * parameters:
 * 	argc: the number of args taken in from the command line
 * 	argv[]: the list of arguments passed in from the command line
 *
 * returns: none
 */
void main(int argc, char* argv[])
{
	char command[50];
	strcpy(command, "echo ");
	if (argc == 1)			//no arguments passed
	{
		system(command);	//call "echo" on nothing
		exit(EXIT_SUCCESS);
	}
	else
	{
		for (int i = 1; i < argc; i++)	//iterate through the args
		{
			strcat(command, argv[i]); //add them to the command
		}
		system(command);		//run the "echo" command on all of them
		exit(EXIT_SUCCESS);
	}
	return;
}

