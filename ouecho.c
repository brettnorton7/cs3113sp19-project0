#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc == 1)			//no arguments passed
	{
		fprintf(stdout, "\n");	//prints only a newline to stdout
		exit(EXIT_SUCCESS);
	}
	else
	{
		for (int i = 1; i < argc; i++)	//iterate through the args
		{
			fprintf(stdout, "%s ", argv[i]);//print off each arg, separated by a space
		}
		fprintf(stdout, "\n");		//end with a newline
		exit(EXIT_SUCCESS);
	}
	return 0;
}
