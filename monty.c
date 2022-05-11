#include "main.h"
unsigned int line;
/**
 * get_op_func - function selector
 * @s: parameter received
 * Return: pointer to function or NULL if fail
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t funciones[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};

	while (i < 7)
	{
		if (strcmp(s, funciones[i].opcode) == 0)
			return (funciones[i].f);
		i++;
	}
	return (NULL);
}
/**
 * tokenizer - tokenize and work with tokens
 * @head: first node of the stack
 * @buffer: obtained line
 * Return: 0 success or -1 if fail
 */
int tokenizer(stack_t **head, char *buffer)
{
	char *cmd = NULL;
	char *integer = NULL, err[20];
	int status = 0;
	instruction_t function;

	cmd = strtok(buffer, " ");
	integer = strtok(NULL, " ");

	if (cmd == NULL)
		return (0);

	function.f = get_op_func(cmd);

	if (function.f == NULL)
	{
		sprintf(err, "%d", line);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": unknown instruction <opcode>\n", 31);
		return (-1);
	}
	status = exec(function, integer, head, line);
	return (status);
}
/**
 * main - Monty's interpreter
 * @argc: number of arguments received
 * @argv: arguments received
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *buffer = NULL, *copy = NULL;
	size_t size = 0;
	int status = 0;
	stack_t *push = NULL;

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "rw+");
	if (fp == NULL)
	{
		write(2, "Error: Can't open file ", 23);
		write(2, "<", 1);
		write(2, argv[1], strlen(argv[1]));
		write(2, ">\n", 2);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fp) != -1)
	{
		line++;
		copy = strdup(buffer);
		copy[strlen(copy) - 1] = '\0';
		status = tokenizer(&push, copy);
		if (status == -1)
		{
			free(copy);
			break;
		}
		free(copy);
	}
	if (buffer)
		free(buffer);
	freelist(push);
	fclose(fp);
	if (status == -1)
		exit(EXIT_FAILURE);
	return (0);
}
