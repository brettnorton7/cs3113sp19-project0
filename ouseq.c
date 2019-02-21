#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void syserrmsg(char * error_message);

void main(int argc, char ** argv)
{
	char command[50];
	strcpy(command, "seq ");				//setting up the command string with the "seq" call

	if ((!strcmp(argv[1], "-h")) && (argc == 2))		//in the evet that there are only two args and the non-calling one is "-h", print the usage statement
	{
		printf("Usage: ouseq [M] N");
		exit(EXIT_SUCCESS);
	}
	if (argc < 3)						//this command should take in at most 2 args, so if there are more than three (including the calling arg) then error
	{
		syserrmsg("too many args");
	}
	else
	{
		int first = atoi(argv[1]);			//otherwise compare the two numbers input
		int second = atoi(argv[2]);
		if (first <= second)				//if the first is the smaller of the two, or equal to the second, then call "seq" normally on them
		{
			strcat(command, argv[1]);
			strcat(command, " ");
			strcat(command, argv[2]);
			system(command);
			exit(EXIT_SUCCESS);
		}
		if (first > second)				//if the second is the smaller of the two, then run "seq" but with the "-1" flag to reverse the direction
		{
			strcat(command, argv[1]);
                        strcat(command, " -1 ");
                        strcat(command, argv[2]);
			system(command);
			exit(EXIT_SUCCESS);
		}
	}
	return;							//should never get here
}
/*
 * method to handle errors by printing a message
 * parameters: 
 * 	error_message: details about why the error was thrown
 *
 * returns: none
 */
void syserrmsg(char * error_message)
{
	fprintf(stderr, "%s", error_message);
	exit(EXIT_FAILURE);
}

