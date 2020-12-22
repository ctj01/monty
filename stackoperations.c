#include "monty.h"
/**
 * pop- check the code for Holberton School students.
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */

void pop(stack_t **stack, unsigned int ln)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	*stack = (*stack)->next;

	free(aux);
}
/**
 * pint- check the code for Holberton School students.
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void pint(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * add_to_stack- check the code for Holberton School students.
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void add_to_stack(stack_t **stack, unsigned int ln)
{
	stack_t *node;
	char *num;
	int i = 0;
	int isNegative = 1;

	num = strtok(NULL, DELIM);
	if (num == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	if (num[0] == '-' && num != NULL)
	{
		num = num + 1;
		isNegative = -1;
	}
	while (num[i] != '\0')
	{
		if (isdigit(num[i]) == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(num) * isNegative;
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}
/**
 * print_stack- check the code for Holberton School students.
 * @stack: arguments
 * @ln: numbers lines
 *  Return: void.
 */
void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *aux = *stack;

	(void) ln;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
