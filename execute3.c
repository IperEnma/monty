#include "monty.h"
/**
 * exe_mul - the function executes f_mul
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_mul(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lin);
		return (-1);
	}

	f_mul(head, lin);
	return (0);
}
/**
 * exe_mod - the function executes f_mod
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_mod(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lin);
		return (-1);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lin);
		return (-1);
	}

	f_mod(head, lin);
	return (0);
}
/**
 * exe_pchar - the function executes f_pchar
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_pchar(stack_t **head, unsigned int lin)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lin);
		return (-1);
	}
	if ((*head)->n < 32 || (*head)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lin);
		return (-1);
	}
	f_pchar(head, lin);
	return (0);
}
