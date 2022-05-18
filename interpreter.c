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
	int status = 1;

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("error while open file\n"); /* falta cambiar */
	}
	while (getline(&line, &bufsize, file) != -1)
	{
		args = split_line(line);
		status = execute_args(args);
		if (status == 1)
		{
			printf("all good\n");
		}
		free(args); /* avoid memory leaks */
	}
	free(line); /* avoid memory leaks */
	fclose(file);
}
