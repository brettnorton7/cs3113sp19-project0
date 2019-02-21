#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void usage_statement();                                                 //method for printing the usage statement
void ouhead(char * file,int lines);
void syserrmsg(char * error_message);

void main(int argc, char* argv[])
{
        int max_lines = 10;                                             //the number of lines that the program will use
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
                if (argc == 2)                                          //if there are only two args
                {
                        if (access(argv[1], F_OK) != -1)		//then the last one will be the file, so check to be sure it exists
                        {
                                char command[50];			//and call tail on it with the default 10 lines
                                strcpy(command, "tail -n 10 ");
                                strcat(command, argv[1]);
                                system(command);
                                exit(EXIT_SUCCESS);
                        }
                        else						//if the file does not exist, then throw an error
                        {
                                syserrmsg("file not found");
                        }
                }

                if (argc > 4)						//again its my understanding that this command should not accomodate multiple files
                {
                        syserrmsg("too many args");			//so more than 4 args throws an error
                }

                else
                {
			if (argc == 4)					//if there are 4 args...
                        {
                                if (access(argv[3], F_OK) == -1)	//then the last one should be the file so check to make sure it exists
                                {
                                        syserrmsg("file not found");	//and if it does not then throw an error
                                }
                        }
                        char command[50];				//otherwise run "tail" on the rest of the args
                        strcpy(command, "tail ");
                        for (int i = 1; i < argc; i++)
                        {
                                strcat(command, argv[i]);
                                strcat(command, " ");
                        }
                        system(command);
                        exit(EXIT_SUCCESS);
                }
        }
        return;								//again the program should never reach this return statement
}

/*
 * method to print the usage statement for the program
 * parameters: none
 * returns: none
 */
void usage_statement()
{
        fprintf(stdout, "usage: outail [-n N] <file>\n");
        exit(EXIT_SUCCESS);
}
/*
 * method to print an error message and exit the program with a failure
 * parameters:
 * 	error_message: details about why the error was thrown
 *
 * returns: none
 */
void syserrmsg(char * error_message)
{
        fprintf(stderr, "Error: %s\n", error_message);
        exit(EXIT_FAILURE);
}
