#include "monty.h"

/**
 * Stack - sets the format of the data to a stack (LIFO).
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void Stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = 0;
}

/**
 * Queue - sets the format of the data to a queue (FIFO).
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void Queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = 1;
}
