#include "monty.h"
/**
 * exe_pop - the function executes f_pop
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_pop(stack_t **head, unsigned int lin)
{
	char err[20];

	if (*head == NULL)
	{
		sprintf(err, "%d", lin);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": can't pop an empty stack\n", 27);
		return (-1);
	}
	f_pop(head, lin);
	return (0);
}
/**
 * exe_swap - the function executes f_swap
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_swap(stack_t **head, unsigned int lin)
{
	char err[20];
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		sprintf(err, "%d", lin);
		write(2, "L", 1);
		write(2, err, strlen(err));
		write(2, ": can't swap, stack too short\n", 30);
		return (-1);
	}
	f_swap(head, lin);
	return (0);
}
/**
 * exe_add - the function executes f_add
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_add(stack_t **head, unsigned int lin)
{
	int len = 0;

	len = lenstack(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lin);
		return (-1);
	}
	f_add(head, lin);
	return (0);
}
/**
 * exe_nop - the function executes f_nop
 * @head: first node of the stack
 * @lin: number line
 * Return: 0 success or -1 if fail
 */
int exe_nop(stack_t **head, unsigned int lin)
{
	f_nop(head, lin);
	return (0);
}
/**
 * exec - check which function was entered
 * @head: first node of the stack
 * @l: number line
 * @function: pointer to function
 * @integer: new stack
 * Return: 0 success or -1 if fail
 */
int exec(instruction_t function, char *integer, stack_t **head, unsigned int l)
{
	int status = 0;

	if (function.f == f_push)
		status = push(function, integer, head, l);
	if (function.f == f_pall)
		status = exe_pall(head);
	if (function.f == f_pint)
		status = exe_pint(head, l);
	if (function.f == f_pop)
		status = exe_pop(head, l);
	if (function.f == f_swap)
		status = exe_swap(head, l);
	if (function.f == f_add)
		status = exe_add(head, l);
	if (function.f == f_sub)
		status = exe_sub(head, l);
	if (function.f == f_div)
		status = exe_div(head, l);
	if (function.f == f_nop)
		status = exe_nop(head, l);
	return (status);

}
