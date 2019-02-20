#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage_statement();							//method for printing the usage statement
void ouhead(char * file,int lines);
void syserrmsg(char * error_message);

int main(int argc, char* argv[])
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
			//char file[50];
			//strcpy(file, argv[1]);				//assume that the second arg is the file name
			//ouhead(file, max_lines);			//try to call ouhead() on it
			if (access(argv[1], F_OK) != -1)
			{
				char command[50];
				strcpy(command, "head -n 10 ");
				strcat(command, argv[1]);
				system(command);
				exit(EXIT_SUCCESS);
			}
			else 
			{
				syserrmsg("file not found");
			}
		}

		if (argc > 4)
		{
			syserrmsg("too many args");
		}

		else
		{
			if (argc == 4)
			{
				if (access(argv[3], F_OK) == -1)
				{
					syserrmsg("file not found");
				}
			}
			char command[50];
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
	return 0;
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

void ouhead(char * file, int lines)
{
	if (access(file, F_OK) != -1)
	{
		char command[50];
		char number[50];
		sprintf(number, "%d ", lines);
		strcpy(command, "head -n ");
		strcat(command, number);
		strcat(command, file);
		system(command);
	}
	else 
	{
		syserrmsg("file not found");
	}
}

void syserrmsg(char * error_message)
{
	fprintf(stderr, "Error: %s\n", error_message);
	exit(EXIT_FAILURE);
}

