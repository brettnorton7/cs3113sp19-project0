#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void syserrmsg(char * error_message);
void ouwc(char * input);
int flag(char * check);

void main(int argc, char ** argv)
{
	FILE * file;
	int l_flag = 0;
	int number_of_bytes = 0;
	int c_flag = 0;
	int number_of_lines = 0;
	char filename[50];

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			if (flag(argv[i]))
			{
				if (!strcmp(argv[i], "-c"))
				{
					c_flag = 1;
				}
				if (!strcmp(argv[i], "-l"))
				{
					l_flag = 1;
				}
			}
			if (!flag(argv[i]))
			{
				file = fopen(argv[i], "r");
				if (file != NULL)
				{
					strcpy(filename, argv[i]);
				}
				if (file == NULL)
				{
					syserrmsg("unrecognized input");
				}
			}
		}
	}

	if (file != NULL)
	{
		char c;
		number_of_lines = 0;
		for (c = getc(file); c != EOF; c = getc(file))
		{
			if (c == '\n')
			{
				number_of_lines ++;
			}
		}
		int file_descriptor = open(filename, O_RDONLY);
		char buffer[1000000];
		number_of_bytes = read(file_descriptor, buffer, 1000000);
		if (l_flag == 1)
                        printf("%8d", number_of_lines);
		if (c_flag == 1)
			printf("%8d", number_of_bytes);
		if ((l_flag == 0) && (c_flag == 0))
		{
			printf("%8d", number_of_lines);
			printf("%8d", number_of_bytes);
		}
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	if (file == NULL)
	{
		char buffer[1000000];
		int i;
		while(i = read(0, buffer, 1000000))
		{
			number_of_lines++;
			number_of_bytes = number_of_bytes + i;
		}
		if (l_flag == 1)
			printf("%8d\n", number_of_lines);
		if (c_flag == 1)
			printf("%8d\n", number_of_bytes);
		if ((l_flag == 0) && (c_flag == 0))
		{
			printf("%8d\n", number_of_lines);
			printf("%8d\n", number_of_bytes);
		}
		exit(EXIT_SUCCESS);
	}

	
	return;											//should never get here
}
/*
 * method for handling error messages and exiting the code in case of an error
 * parameters: 
 * 	error_message: details about the reason the code threw an error
 *
 * returns: none
 */
void syserrmsg(char * error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

/*
 * method for checking whether a given input is one of the valid flags for this command
 * parameters: 
 * 	check: the string to be compared to the list of valid flags
 *
 * returns:
 * 	is_flag: 1 if the parameter "check" is one of the valid flags, 0 if it is not
 *
 * notes: 
 * 	this method allows for a growing list of acceptable flags, but the number of flags 
 * 	will need to be updated each time a new acceptable flag is added
 */
int flag(char * check)
{
	int number_of_flags = 2;
	char * list_of_flags[] = {"-l", "-c"};
	int is_flag = 0;
	for (int i = 0; i < number_of_flags; i++)
	{
		if (strcmp(check, list_of_flags[i]) == 0)
		{
			is_flag = 1;
		}
	}
	return is_flag;
}
