#include "monty.h"

/**
 * instr_add - adds the top two elements of the stack.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_add(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	instr_pop(stack, line_number);
	(*stack)->n += temp;
}

/**
 * instr_sub - subtracts the top element of the stack from the second top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	instr_pop(stack, line_number);
	(*stack)->n -= temp;
}

/**
 * instr_div - divides the second top element of the stack by the top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_div(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	instr_pop(stack, line_number);
	(*stack)->n /= temp;
}

/**
 * instr_mul - multiplies the second top element of the stack with the top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	instr_pop(stack, line_number);
	(*stack)->n *= temp;
}

/**
 * instr_mod -  computes the rest of division of the second element by the top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	instr_pop(stack, line_number);
	(*stack)->n %= temp;
}
