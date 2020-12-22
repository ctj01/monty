#include  "monty.h"

/**
 * free_list - globally frees memory, previously alocated in the program
 *
 * Return: void
 */
void free_list(void)
{
	stack_t *tmp;
	stack_t *aux = NULL;

	tmp = *head;

	while (tmp)
	{
		aux = tmp->next;

		free(tmp);

		tmp = aux;
	}
}
/**
 * findoperation- check the code for Holberton School students.
 * @code: arguments
 * @ln: numbers lines
 * @stack: list
 *  Return: void.
 */
void findoperation(char *code, int ln, stack_t **stack)
{
	int i = 0;

	instruction_t builtins[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap_stack},
		{"add", add_top2_stack},
		{"nop", nop_stack},
		{"sub", sub_top2_stack},
		{"div", div_top2_stack},
		{"mul", mul_top2_stack},
		{"mod", mod_top2_stack},
		{"pchar", pchar_top_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
		{NULL, NULL}
	};

	if (code[0] == '#')
		return;

	for (i = 0; builtins[i].opcode; i++)
	{
		if (strcmp(code, builtins[i].opcode) == 0)
		{
			builtins[i].f(stack, ln);
			return;
		}
	}
	if (strlen(code) != 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: unknown instruction %s\n", ln, code);
		exit(EXIT_FAILURE);
	}


}
