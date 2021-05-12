#include "monty.h"

global_variables globv;
void set_to_global(void);

/**
* main - program that interpretate the monty lenguage
* @argc: number of arguments
* @argv: value of the arguments
* Return: 0
*/

int main(int argc, char *argv[])
{
	char *buffer = NULL, *file = argv[1], *tokenize = NULL, *DELIMITER = " \n\t";
	size_t buff_size = 0;
	ssize_t size;
	FILE *fptr;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fptr = fopen(file, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	set_to_global();
	globv.fptr = fptr;
	size = getline(&buffer, &buff_size, globv.fptr);
	globv.buffer = buffer;
	while (size >= 0)
	{
		globv.line_number += 1;
		tokenize = strtok(buffer, DELIMITER);
		if (tokenize != NULL && tokenize[0] != '#')
		{
			globv.n = strtok(NULL, DELIMITER);
			get_op(tokenize);
		}
		size = getline(&buffer, &buff_size, globv.fptr);
		tokenize = NULL;
		globv.n = NULL;
	}
	free(globv.buffer);
	fclose(globv.fptr);
	free_stack(globv.head);
	return (0);
}

/**
* set_to_global - set variables to global
*/

void set_to_global(void)
{
	globv.head = NULL;
	globv.line_number = 0;
	globv.buffer = NULL;
	globv.n = NULL;
}
