#include "main.h"
unsigned int line;
/**
 *
 *
 *
 */
void (*get_op_func(char *s))
{
	int i = 0;

	instruction_t funciones[] = 
	{
		{"push", f_push},
		{"pall", f_pall},
		{NULL, NULL}
	};

	while (i < 2)
	{
		if (strcmp(s, funciones[i].opcode) == 0)
			return (funciones[i].f);
		i++;
	}
	return (NULL);
}
/**
 *
 *
 *
 */
int tokenizer(stack_t **head, char *buffer)
{
	char *cmd = NULL;
	char *integer = NULL, err[20];
	int status = 0;
	unsigned int num = 0;
	instruction_t function;
	
	cmd = strtok(buffer, " ");
	integer = strtok(NULL, " ");

	function.f = get_op_func(cmd);

	if (function.f == NULL)
	{
		sprintf(err, "%d", line);
		write(2, "L<",2);
		write(2, err, strlen(err));
		write(2,">: unknown instruction <opcode>\n", 32);
		return (-1);
	}

	status = execute(function, integer, head, line);

	return (status);
}
/**
 *
 *
 *
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *buffer = NULL;
	char *copy = NULL;
	size_t size = 0;
	ssize_t character = 1;
	int status = 0;
	stack_t *push = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "rw+");
	if (fp == NULL)
	{
		write(2, "Error: Can't open file ", 23);
		write(2, "<", 1);
		write(2, argv[1], strlen(argv[1]));
		write(2, ">\n", 2);
		exit (EXIT_FAILURE);
	}
	
	while (getline(&buffer, &size ,fp) != -1)
	{
		line++;
		copy = strdup(buffer);
		copy[strlen(copy) - 1] = '\0';
		status = tokenizer(&push, copy);
		if (status == -1)
			exit (EXIT_FAILURE);
		if (character == -1)
			break;
	}
	free(copy);
	fclose(fp);
	return(0);
}
