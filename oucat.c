#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void usage_statement();
void syserrmsg(char * error_message);

void main(int argc, char ** argv)
{
	char buffer[1000000];					//buffer to hold read the lines of text into
	if (argc == 1)
	{
		while(read(0, buffer, 1000000) > 0)		//read in the line of user input
		{
			fprintf(stdout, "%s", buffer);		//print the input
		}
	}
	else 
	{
		for(int i = 1; i < argc; i++)			//if there is a file
		{
			int file = open(argv[i], O_RDONLY);	//open it
			if (file == -1)				//throw an error if the file cannot be opened
				syserrmsg("file not found");
			while(read(file, buffer, 1000000) > 0)	//ierate through the lines of the file
			{
				fprintf(stdout, "%s", buffer);	//print each one out
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

