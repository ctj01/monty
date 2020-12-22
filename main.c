#include "monty.h"

stack_t **head;

/**
 * main- check the code for Holberton School students.
 * @argc: arguments
 * @argv: arguments
 *  Return: void.
 */
int main(int argc, char *argv[])
{
	stack_t *node;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	node = NULL;
	head = &node;
	read_file(argv[1], &node);
	free_list();
	exit(EXIT_SUCCESS);
}
