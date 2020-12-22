#include "monty.h"

/**
 * pchar_top_stack- prints the char at the top of the stack
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void pchar_top_stack(stack_t **stack, unsigned int ln)
{
	stack_t *top = *stack;

	if (!top)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	if (top->n < 0 || top->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}

/**
 * pstr_stack- prints the string starting at the top of the stack
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void pstr_stack(stack_t **stack, unsigned int ln)
{
	stack_t *top = *stack;
	(void)ln;

	if (!top)
	{
		putchar('\n');
		return;
	}

	while (top && top->n != 0 && top->n >= 0 && top->n <= 127)
	{
		printf("%c", top->n);
		top = top->next;
	}
	putchar('\n');
}
/**
 * rotl_stack- rotates the stack to the top
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void rotl_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux = *stack;

	(void)ln;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (aux->next)
		aux = aux->next;

	aux->next = *stack;
	aux->next->prev = aux;
	*stack = (*stack)->next;
	aux->next->next = NULL;
	(*stack)->prev = NULL;

}
/**
 * rotr_stack- rotates the stack to the bottom
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void rotr_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux = *stack;

	(void)ln;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (aux->next != NULL)
		aux = aux->next;

	aux->next = *stack;
	aux->prev->next = NULL;
	aux->prev = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
