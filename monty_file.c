#include "monty.h"

global_t glob;

/**
 * stack_st - starts the stack
 * @top: head of stack
 */
void stack_st(stack_t **top)
{
	*top = NULL;
	glob.top = top;
}

/**
 * freevery - frees memory allocated through malloc
 * Return: Nothing
 */
void freevery(void)
{
	stack_t *temp, *new_temp = NULL;

	temp = *(glob.top);
	while (temp != NULL)
	{
		new_temp = temp->next;
		free(temp);
		temp = new_temp;
	}
}

/**
 * main - monty bytecode interpreter
 * @argc: argument counter
 * @argv: argument values
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	stack_t *top;

	stack_st(&top);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	File_oper(argv[1], &top);
	exit(EXIT_SUCCESS);
}
