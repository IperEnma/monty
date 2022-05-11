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
	char err[20];

	if (*head == NULL)
	{
		sprintf(err, "%d", lin);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": can't pint, stack empty\n", 27);
		return (-1);
	}
	f_pint(head, lin);
	return (0);
}
