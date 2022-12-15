#include "monty.h"

/**
 * instr_rotl - rotates the stack to the top.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *newtop;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	newtop = (*stack)->next;
	newtop->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp;
	(*stack) = newtop;
}

/**
 * instr_rotr - rotates the stack to the bottom.
 * @stack: double pointer to head of stack
 * @line_number: line number in bytecode file
 * Return: Nothing
 */
void instr_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
