#ifndef _montyh_
#define _montyh_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define DELIM "\n "
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t **head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void findoperation(char *code, int ln, stack_t **stack);
void print_stack(stack_t **stack, unsigned int ln);
void add_to_stack(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void pint(stack_t **stack, unsigned int ln);
void read_file(char *name, stack_t **stack);
void free_list(void);
void swap_stack(stack_t **stack, unsigned int ln);
void add_top2_stack(stack_t **stack, unsigned int ln);
void nop_stack(stack_t **stack, unsigned int line_number);
void sub_top2_stack(stack_t **stack, unsigned int ln);
void mul_top2_stack(stack_t **stack, unsigned int ln);
void div_top2_stack(stack_t **stack, unsigned int ln);
void mod_top2_stack(stack_t **stack, unsigned int ln);
void pchar_top_stack(stack_t **stack, unsigned int ln);
void pstr_stack(stack_t **stack, unsigned int ln);
void rotl_stack(stack_t **stack, unsigned int ln);
void rotr_stack(stack_t **stack, unsigned int ln);

#endif
