#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void syserrmsg(char * error_message);

void main(int argc, char ** argv)
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "-h"))			//if one arg is passed in, and its "-h", the print the usage statement
		{
			printf("Usage: ouseq [M] N");
			exit(EXIT_SUCCESS);
		}
		int value = atoi(argv[1]);			//otherwise one arg should be a number, so cast to an int
		for(int i = 0; i < value; i++)			//and print numbers counting to it from 0
		{
			printf("%d\n", i);
		}
		exit(EXIT_SUCCESS);
	}
	if (argc < 3)						//cant have more than two extra args
	{
		syserrmsg("too many arguments");
	}
	if (argc == 1)						//must pass in at least one number
	{
		syserrmsg("too few args");
	}
	else 							//otherwise see which value is bigger, and count from the first to the second
	{
		int value1 = atoi(argv[1]);
		int value2 = atoi(argv[2]);

		if (value1 == value2)
		{
			printf("%d\n", value1);
			exit(EXIT_SUCCESS);
		}
		else if (value1 < value2)
		{
			for (int i = value1; i <= value2; i++)
			{
				printf("%d\n", i);
			}
			exit(EXIT_SUCCESS);
		}
		else if (value1 > value2)
		{
			for (int i = value1; i >= value2; i--)
			{
				printf("%d\n", i);
			}
			exit(EXIT_SUCCESS);
		}
	}
	return;
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

