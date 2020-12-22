#include "monty.h"

/**
 * swap_stack- swaps the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void swap_stack(stack_t **stack, unsigned int ln)
{

	stack_t *aux;
	stack_t *auxHead = *stack;

	if (!auxHead || !auxHead->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = auxHead->next;
	auxHead->next = aux->next;
	if (aux->next)
		aux->next->prev = auxHead;
	aux->next = auxHead;
	auxHead->prev = aux;
	aux->prev = NULL;
	auxHead = aux;
	*stack = auxHead;
}

/**
 * add_top2_stack- add the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void add_top2_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux;
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	sum = aux->n + aux->next->n;
	aux->next->n = sum;
	(*stack) = aux->next;

	free(aux);
}

/**
 * nop_stack - handles the nop instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void nop_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
