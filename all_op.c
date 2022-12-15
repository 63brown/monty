#include "monty.h"

/**
 * assign_opr - based on tokens from single line, decide what function to call
 * @stack: double pointer to head of stack data structure
 * @opr: operator, aka token[0] from getline
 * @line_number: line in byte-code file being processed, zero indexed
 * Return: int for mysterious purposes
 */
void assign_opr(stack_t **stack, char *opr, unsigned int line_number)
{
	int i = 0;
	instruction_t all_ops[] = {
		{"push", instr_push},
		{"pall", instr_pall},
		{"pint", instr_pint},
		{"pop", instr_pop},
		{"swap", instr_swap},
		{"add", instr_add},
		{"nop", instr_nop},
		{"sub", instr_sub},
		{"div", instr_div},
		{"mul", instr_mul},
		{"mod", instr_mod},
		{"pchar", instr_pchar},
		{"pstr", instr_pstr},
		{"rotl", instr_rotl},
		{"rotr", instr_rotr},
		{"stack", Stack},
		{"queue", Queue},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(opr, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(stack, line_number);
			return;
		}
	}
	if (strlen(opr) != 0 && opr[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_number, opr);
		exit(EXIT_FAILURE);
	}
}
