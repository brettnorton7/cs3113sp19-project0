#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command[50];

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		system("cat");
		return EXIT_SUCCESS;
	}
	if (strcmp(argv[1], "-h") == 0)
	{
		fprintf(stdout,"Usage: oucat <files>\n");
		return EXIT_SUCCESS;
	}
	else 
	{
		for (int i = 1; i <= argc-1; i++)
		{
			strcpy(command, "cat ");
			strcat(command, argv[i]);
			system(command);
		}
		return EXIT_SUCCESS;
	}
	return 0;
}
