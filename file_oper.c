#include "monty.h"

/**
 * File_oper - operates monty file
 * @Filename: name of monty opcode file
 * @stack: double pointer to top of stack
 * Return: error message or EXIT_SUCCESS
 */
int File_oper(char *Filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char *line = NULL;
	FILE *fptr;
	char *opr;

	if (Filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", Filename);
		exit(EXIT_FAILURE);
	}
	fptr = fopen(Filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", Filename);
		exit(EXIT_FAILURE);
	}
	atexit(freevery);
	while ((read = getline(&line, &len, fptr)) != -1)
	{
		opr = strtok(line, "\n\t\r ");
		line_number++;
		if (opr)
			assign_opr(stack, opr, line_number);
	}
	free(line);
	fclose(fptr);
	return (EXIT_SUCCESS);
}
