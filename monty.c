#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
unsigned int line = 0;
/**
 *
 *
 *
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 *
 *
 *
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed", 21);
		exit (EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
/**
 *
 *
 *
 */
int isnum(char *integer)
{
	int i = 0;
	
	for(i = 0; integer[i]; i++)
	{
		if (integer[i] < 48 || integer[i] > 57)
			return (-1);
	}
	return (0);	
}
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
	
	if (function.f == f_push)
	{
		status = isnum(integer);
		if (status == -1)
		{
			sprintf(err, "%d", line);
			write(2, "L<",2);
			write(2, err, strlen(err));
			write(2,">: usage: push integer\n", 23);
			return (-1);
		}
		num = atoi(integer);
		function.f(head, num);
	}
	 if (function.f == f_pall)
	 {
		 f_pall(head, line);
	 }
	return (0);
}
/**
 *
 *
 *
 */
void load_ins()
{

}
/**
 *
 *
 *
 */
void main(int argc, char *argv[])
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
}
