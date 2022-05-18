#include "monty.h"

/**
 * interpreter - function that open, reads and execute the
 *               commands in the Bytecode file
 * @argv: argument vector - argv[1] is the file to be open
 *
 * Return: void
 */
void interpreter(char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t bufsize = 0;
	char **args;
	void (*function)(stack_t **, unsigned int);
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &bufsize, file) != -1)
	{
		args = split_line(line);
		function = get_function(args[0]);
		if (function == NULL)
		{
			printf("Invalid command\n");
			exit(EXIT_FAILURE);
		}
		function(&stack, line_number);
		line_number++;
		free(args);
	}
	free(line);
	fclose(file);
}
