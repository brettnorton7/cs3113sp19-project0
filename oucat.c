#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void usage_statement();
void oucat();
void syserrmsg(char * error_message);

/*
 * main method for the program
 * parameters:
 * 	argc: the number of args taken in from the command line
 * 	argv: an array of strings taken in from the command line
 *
 * returns: a dummy int with no meaning
 */
int main(int argc, char ** argv)
{
	if (argc == 1) 				//if there are no arguments but the call, then call the regular cat with no pointers
	{
		system("cat");
		return EXIT_SUCCESS;
	}
	if (!strcmp(argv[1], "-h"))		//if the first arg is "-h" then print off the usage statement
	{
		usage_statement();
	}
	else 					//in any other case...
	{
		for (int i = 1; i <= argc-1; i++) //iterate through the args
		{
			oucat(argv[i]);		//try to call oucat() on each arg, a bad one will case an EXIT_FAILURE
		}
		exit(EXIT_SUCCESS);		//if the program successfully calls oucat() on all args (therefore didnt get an EXIT_FAILURE), then EXIT_SUCCESS
	}
	return 0;
}

/*
 * mothod to print off the usage statement for the program
 * parameters: none
 * returns: none
 */
void usage_statement()
{
	fprintf(stdout, "useage: oucat <files>\n");
	exit(EXIT_SUCCESS);
}

void oucat(char file_name[])			//method to print off the contents of a file	
{
	if (access(file_name, F_OK) != -1)	//check to see if the file exists, if it does then use a system call to cat the file passed in
	{
		char command[50];
		strcpy(command, "cat ");
		strcat(command, file_name);
		system(command);
	}
	else					//if the file does not exist, then call the error message method and EXIT_FAILURE
	{
		syserrmsg("file not found");
		exit(EXIT_FAILURE);
	}
}

/*
 * method to handle error messages
 * parameters
 * error_message: a string about the nature of the error
 * returns: none
 */
void syserrmsg(char * error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

