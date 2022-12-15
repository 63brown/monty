#include "monty.h"

/**
 * instr_nop -  doesn’t do anything.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}

/**
 * instr_swap - swaps the top two elements of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	(*stack)->prev = temp;
	if (temp->next)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack) = (*stack)->prev;
}

/**
 * instr_pchar - prints the char at the top of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	if (!(i >= 0 && i <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(i);
	putchar('\n');
}

/**
 * instr_pstr - prints the string starting at the top of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)(line_number);
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temp != NULL)
	{
		if (isascii(temp->n) && temp->n != 0)
			putchar(temp->n);
		else
			break;
		temp = temp->next;
	}
	putchar('\n');
}
