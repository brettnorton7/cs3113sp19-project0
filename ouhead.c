#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage_statement();							//method for printing the usage statement
void ouhead(char * file,int lines);
void syserrmsg(char * error_message);

void main(int argc, char* argv[])
{
	int lines = 10;						//the number of lines that the program will use
	char buffer[1000000];
	FILE * file;
	if (argc == 1)						//if there is only one arg, then its use default lines and read in lines from stdin
	{
		for(int i = 0; i < lines; i++)
		{
			scanf("%s", buffer);
			printf("%s\n", buffer);
		}
		exit(EXIT_SUCCESS);
	}
	if (argc == 2)						//if there are two args, the second should either be a file or -h
	{
		if (!strcmp(argv[1], "-h"))			//if the only arg is "-h" then print the usage statement
			usage_statement();
		file = fopen(argv[1], "r");			//otherwise try to open the arg
		if(file == NULL)
			syserrmsg("file not found");
		char c;
                int i = 0;
                for (c = getc(file); c != EOF; c = getc(file))	//count the number of lines in the file
                {
                        if (c == '\n')
                        {
                                i ++;
                        }
                }
                if (i < lines)					//if the program is asking for more lines than the program has, they just print the program
                        lines = i;

                fclose(file);
                file = fopen(argv[1], "r");			//reopen file to reset the file offset
                for(int i = 0; i < lines; i ++)
                {
                        fgets(buffer, 1000000, file);		//print out the lines
                        printf("%s", buffer);
                }
                exit(EXIT_SUCCESS);
	}
	if (argc == 3)						//if there are three args then the second and third should be "-n" and an int
	{
		if (strcmp(argv[1], "-n"))
			syserrmsg("flag not recognized");
		lines = atoi(argv[2]);
		for(int i = 0; i < lines; i ++)			//keep reading and outputing until you get to the correct number of lines
                {
                        fgets(buffer, 1000000, stdin);
                        printf("%s", buffer);
                }
		exit(EXIT_SUCCESS);
	}
	if (argc == 4)						//if there are four args then they should be "-n", an int, and a file respectively
	{
		if (strcmp(argv[1], "-n"))
			syserrmsg("flag not recognized");
		lines = atoi(argv[2]);
		file = fopen(argv[3], "r");			//argv[3] should hold the file, so try to open it
		if (file == NULL)
			syserrmsg("file not found");
		
		char c;
                int i = 0;
                for (c = getc(file); c != EOF; c = getc(file))	//count the number of lines in the file
                {
                        if (c == '\n')
                        {
                                i ++;
                        }
                }
		if (i < lines)					//switch if necessary
			lines = i;
		
		fclose(file);
		file = fopen(argv[3], "r");			//reopen to reset the file offset
		for(int i = 0; i < lines; i ++)
                {
                        fgets(buffer, 1000000, file);		//print lines
                        printf("%s", buffer);
                }
		exit(EXIT_SUCCESS);
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

