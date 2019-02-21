#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void syserrmsg(char * error_message);
void ouwc(char * input);
int flag(char * check);

void main(int argc, char ** argv)
{
	char input[50];										//string to hold the args to be passed to ouwc()
	FILE * file;
	int l_flag = 0;
	int c_flag = 0;

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
				if (file == NULL)
				{
					syserrmsg("unrecognized input");
				}
			}
		}
	}
	/*

	if (argc == 1)
	{
		strcpy(input, " ");
		ouwc(input);
	}
	if (argc == 2)										//if there are exactly 2 args...
	{
		if (!strcmp(argv[1], "-h"))							//and the second is the "-h" flag, then output the usage statement and exit success
		{
			printf("usage: [-l | -c] <file>\n");
			exit(EXIT_SUCCESS);
		}
		//
		else 										//otherwise argv[1] should be a file, so check if it exists
		{
			if (access(argv[1], F_OK) != -1)					//and if it does then call ouwc() on it with the standard flags
			{
				strcpy(input, "-l -c ");
				strcat(input, argv[1]);
				ouwc(input);
			}
			else 									//if it does not exist then throw an error
			{
				syserrmsg("file not found");
			}
		}
		
	} 
	strcpy(input, "wc ");
	for (int i = 1; i < argc; i++)
	{
		if ((flag(argv[i])) || (access(argv[i], F_OK) != -1))
		{
			strcat(input, argv[i]);
			printf("%s added\n", argv[i]);
		}
		else
		{
			syserrmsg("input must be valid flag or file");
		}
	}
	ouwc(input);
	
	else 
	{
		if (argc == 3)									//if there are 3 args then there should be one flag in the argv[1] position
		{
			if (!flag(argv[1]))							//if it isnt one of the valid flags, then throw an error
			{
				syserrmsg("flag not recognized");
			}
		}
		if (argc == 4)									//if there are 4 args the argv[1] and argv[2] should be flags
		{
			if (!flag(argv[1]))							//if either is not then throw an error
			{
				syserrmsg("first flag not recognized");
			}
			if (!flag(argv[2]))
			{
				syserrmsg("second flag not recognized");
			}
		}
		if (argc > 4)									//if a user tries to give more than four args (call, two flags, and a file)
		{
			syserrmsg("too many arguments");					//then throw an error
		}
		if (access(argv[argc - 1], F_OK) != -1)						//otherwise the last arg should always be the file, so check if it exists
		{
			for (int i = 1; i < argc; i++)						//if it does then take all of the args except the first and feed them to ouwc()
			{
				strcat(input, argv[i]);
				strcat(input, " ");
			}
			ouwc(input);
		}
		else 										//if it does not exist, then throw an error
		{
			syserrmsg("file not found");
		}
	}
	*/

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
 * method for actually calling "wc" on the args passed in
 * parameters: 
 * 	input: a string of all of arguments, both flags and file name, concatenated together by the main method
 *
 * returns: none
 */
void ouwc(char * input)
{
	char command[50];

	strcpy(command, "wc ");
	strcat(command, input);
	system(command);
	exit(EXIT_SUCCESS);
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
