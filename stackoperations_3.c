#include "monty.h"

/**
 * sub_top2_stack- subtract the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void sub_top2_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux;
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	sum = aux->next->n - aux->n;
	aux->next->n = sum;
	(*stack) = aux->next;

	free(aux);
}

/**
 * mul_top2_stack- muliply the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void mul_top2_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux;
	int mul;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	mul = aux->next->n * aux->n;
	aux->next->n = mul;
	(*stack) = aux->next;

	free(aux);
}

/**
 * div_top2_stack- division the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void div_top2_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux;
	int div;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	div = aux->next->n / aux->n;
	aux->next->n = div;
	(*stack) = aux->next;

	free(aux);
}

/**
 * mod_top2_stack- get module of the top two elements of the stack;
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void mod_top2_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux;
	int mod;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	mod = aux->next->n % aux->n;
	aux->next->n = mod;
	(*stack) = aux->next;

	free(aux);
}
