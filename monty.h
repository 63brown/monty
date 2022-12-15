#ifndef MONTY
#define MONTY

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - useful global variables
 * @top: double pointer to head of stack
 * @ops: double pointer to an instruction struct
 */
typedef struct global_s
{
	stack_t **top;
	instruction_t **ops;
} global_t;

extern global_t glob;

/**
 * struct variable_s - variables to represent mode
 * @queue: flag to show if in stack vs queue mode
 * @sz: size of the stack
 */
typedef struct variable_s
{
	int queue;
	size_t sz;
} variable_t;

variable_t var;

void stack_init(stack_t **head);
void freevery(void);
int File_oper(char *Filename, stack_t **stack);
void assign_opr(stack_t **stack, char *opr, unsigned int line_number);
int mdf_strtol(char *num_str, unsigned int line_number);
void instr_push(stack_t **stack, unsigned int line_number);
void instr_pall(stack_t **stack, unsigned int line_number);
void instr_pint(stack_t **stack, unsigned int line_number);
void instr_pop(stack_t **stack, unsigned int line_number);
void instr_swap(stack_t **stack, unsigned int line_number);
void instr_add(stack_t **stack, unsigned int line_number);
void instr_nop(stack_t **stack, unsigned int line_number);
void instr_sub(stack_t **stack, unsigned int line_number);
void instr_div(stack_t **stack, unsigned int line_number);
void instr_mul(stack_t **stack, unsigned int line_number);
void instr_mod(stack_t **stack, unsigned int line_number);
void instr_pchar(stack_t **stack, unsigned int line_number);
void instr_pstr(stack_t **stack, unsigned int line_number);
void instr_rotl(stack_t **stack, unsigned int line_number);
void instr_rotr(stack_t **stack, unsigned int line_number);
void Stack(stack_t **stack, unsigned int line_number);
void Queue(stack_t **stack, unsigned int line_number);

#endif
