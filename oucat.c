#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void usage_statement();
void oucat();
void syserrmsg(char * error_message);

void main(int argc, char ** argv)
{
	char buffer[1000000];
	if (argc == 1)
	{
		while(read(0, buffer, 1000000) > 0)
		{
			fprintf(stdout, "%s", buffer);
		}
	}
	else 
	{
		for(int i = 1; i < argc; i++)
		{
			int file = open(argv[i], O_RDONLY);
			if (file == -1)
				syserrmsg("file not found");
			while(read(file, buffer, 1000000) > 0)
			{
				//write(1, buffer, (sizeof(buffer)/sizeof(buffer[0])));
				fprintf(stdout, "%s", buffer);
			}
		}
	}
	return;
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

