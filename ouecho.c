#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command[50];			//char array for the storage of the system command

int main(int argc, char* argv[])
{
	if (argc == 1)			//no arguments passed
	{
		fprintf(stdout, "\n");	//prints only a newline to stdout
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("%d\n", argc);
		strcpy(command, "echo ");		//set up the command with echo
		for (int i = 1; i <= argc-1; i++)	//iterate through the args
		{
			strcat(command, argv[i]);
			strcat(command, " ");
		}
		system(command);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
