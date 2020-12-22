#include "monty.h"
/**
 * read_file- check the code for Holberton School students.
 * @stack: arguments
 * @name: nume of file
 *  Return: void.
 */
void read_file(char *name, stack_t **stack)
{
	int line_n;
	char *lineprt;
	size_t n;
	char *command;
	FILE *fd;

	lineprt = NULL;
	n = 0;

	fd = fopen(name, "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	for (line_n = 1; getline(&lineprt, &n, fd) != EOF; line_n++)
	{
		if (lineprt[0] == '#')
			continue;
		command = strtok(lineprt, DELIM);
		if (command)
			findoperation(command, line_n, stack);
	}
	free(lineprt);
	fclose(fd);
}
