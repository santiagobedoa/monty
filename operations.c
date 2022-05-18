#include "monty.h"

int push(char **args)
{
	printf("%s | ", args[0]);
	printf("%s\n", args[1]);
	return (0);
}

int pall(char **args)
{
	printf("%s - %s\n", args[0], args[1]);
	return (0);
}
