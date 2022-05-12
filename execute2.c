#include "monty.h"
/**
 * exe_pall - the function executes f_pall
 * @head: first node of the stack
 * Return: 0
 */
int exe_pall(stack_t **head)
{
	f_pall(head, 2);
	return (0);
}
/**
 * push - the function executes f_pall
 * @head: first node of the stack
 * @function: pointer tu function
 * @integer: new stack
 * @l: number line
 * Return: 0 success or -1 if fail
 */
int push(instruction_t function, char *integer, stack_t **head, unsigned int l)
{
	int status = 0, num = 0;
	char err[20];

	status = isnum(integer);
	if (status == -1)
	{
		sprintf(err, "%d", l);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": usage: push integer\n", 22);
		return (-1);
	}
	num = atoi(integer);
	function.f(head, num);
	return (0);
}
/**
 * exe_pint - the function executes f_pall
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_pint(stack_t **head, unsigned int lin)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lin);
		return (-1);
	}
	f_pint(head, lin);
	return (0);
}
/**
 * exe_sub - the function executes f_sub
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_sub(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", lin);
		return (-1);
	}
	f_sub(head, lin);
	return (0);
}
/**
 * exe_div - the function executes f_div
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_div(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lin);
		return (-1);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lin);
		return (-1);
	}

	f_div(head, lin);
	return (0);
}
