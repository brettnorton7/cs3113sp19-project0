#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage_statement();							//method for printing the usage statement
void ouhead(char * file,int lines);
void syserrmsg(char * error_message);

void main(int argc, char* argv[])
{
	int max_lines = 10;						//the number of lines that the program will use
	if (argc == 1)
	{
		//no_file(max_lines);
	}
	if (strcmp(argv[1], "-h") == 0)                                 //if the user asks for the usage statment...
        {
                usage_statement();                                      //call the usage_statement method
        }
	else 
	{
		if (argc == 2)						//if there are only two args
		{
			if (access(argv[1], F_OK) != -1)		//then the second should be a file, so make sure that it exists
			{
				char command[50];			//and call head on it with the default 10 lines
				strcpy(command, "head -n 10 ");
				strcat(command, argv[1]);
				system(command);
				exit(EXIT_SUCCESS);
			}
			else 						//if the file does not exist, then throw an error
			{
				syserrmsg("file not found");
			}
		}

		if (argc > 4)						//my understanding is that this program can only have one file, which means max four args
		{
			syserrmsg("too many args");			//and if there are more then that is an error
		}

		else
		{
			if (argc == 4)					//if there are four args, then the last one argv[3] should be the file
			{
				if (access(argv[3], F_OK) == -1)	//and if it doesnt exist then thats an error
				{
					syserrmsg("file not found");
				}
			}
			char command[50];				//otherwise call head with the rest of the arguments
			strcpy(command, "head ");
			for (int i = 1; i < argc; i++)
			{
				strcat(command, argv[i]);
				strcat(command, " ");
			}
			system(command);
			exit(EXIT_SUCCESS);
		}
	}
	return;								//should never get here, but just in case
}

/*
 * method to print the usage statement for the program
 * parameters: none
 * returns: none
 */
void usage_statement()
{
	fprintf(stdout, "usage: ouhead [-n N] <file>\n");
	exit(EXIT_SUCCESS);
}

/*
 * method to print an error message and exit the code with a failure
 * parameters
 * 	error_message: details about why the error was thrown
 *
 * returns: none
 */
void syserrmsg(char * error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

