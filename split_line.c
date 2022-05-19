#include "monty.h"

/**
 * split_line - split a string into multiple strings
 * @line: string to be splited
 *
 * Return: pointer to an array with the strings
 */
char **split_line(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Error: malloc failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
