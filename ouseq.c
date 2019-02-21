#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void syserrmsg(char * error_message);

void main(int argc, char ** argv)
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "-h"))
		{
			printf("Usage: ouseq [M] N");
			exit(EXIT_SUCCESS);
		}
		int value = atoi(argv[1]);
		for(int i = 0; i < value; i++)
		{
			printf("%d\n", i);
		}
		exit(EXIT_SUCCESS);
	}
	if (argc < 3)
	{
		syserrmsg("too many arguments");
	}
	if (argc == 1)
	{
		syserrmsg("too few args");
	}
	else 
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

