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
	if (argc > 1)					//if something is passed in
	{
		for (int i = 1; i < argc - 1; i++)
		{
			printf("%s ",argv[i]);		//print each argument
		}
		printf("%s", argv[argc - 1]);		//print the last one without the trailing space
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else 						//otherwise print a newline
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	return;
}

