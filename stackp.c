#include "monty.h"

/**
 * instr_push - pushes an element to the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_push(stack_t **stack, unsigned int line_number)
{
	stack_t *item = malloc(sizeof(stack_t));
	char *opr;
	int value;

	if (!item)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opr = strtok(NULL, "\n\t\r ");
	if (opr == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = mdf_strtol(opr, line_number);
	item->n = value;
	item->prev = NULL;
	item->next = *stack;
	if (item->next != NULL)
		(item->next)->prev = item;
	*stack = item;
}

/**
 * instr_pall - prints all the values on the stack,from the top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *item = *stack;

	(void)(line_number);
	while (item != NULL)
	{
		printf("%d\n", item->n);
		item = item->next;
	}
}

/**
 * instr_pint - prints the value at the top of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * instr_pop - removes the top element of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *item;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	item  = *stack;
	(*stack) = (*stack)->next;
	free(item);
}
