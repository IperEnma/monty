#include "main.h"
/**
 *
 *
 *
 */
int exe_pop(stack_t **head, unsigned int lin)
{
	char err[20];

	if (*head == NULL)
	{
		sprintf(err, "%d", lin);
		write(2, "<L", 2);
		write(2, err, strlen(err));
		write(2, ">: can't pop an empty stack\n", 28);
		return (-1);
	}
	f_pop(head, lin);
	return (0);	
}
int exe_swap(stack_t **head, unsigned int lin)
{
	char err[20];
	int len = 0;

	len = lenstack(head);
	
	if (len < 2)
	{
		sprintf(err, "%d", lin);
		write(2, "<L", 2);
		write(2, err, strlen(err));
		write(2, ">: can't swap, stack too short\n", 31);
		return (-1);
	}
	f_swap(head, lin);
	return (0);
}
int exe_add(stack_t **head, unsigned int lin)
{
	char err[20];
	int len = 0;
	
	len = lenstack(head);
	if (len < 2)
	{
		sprintf(err, "%d", lin);
		write(2, "<L", 2);
		write(2, err, strlen(err));
		write(2, ">: can't add, stack too short\n", 31);
		return (-1);
        }
	f_add(head, lin);
	return (0);
}
/**
 *
 *
 *
 */
int exe_nop(stack_t **head, unsigned int lin)
{
	f_nop(head, lin);
	return (0);
}
/**
 *
 *
 *
 */
int execute(instruction_t function, char *integer, stack_t **head, unsigned int lin)
{
	int status = 0;

	if (function.f == f_push)
		status = exe_push(function, integer, head, lin);
	if (function.f == f_pall)
		status = exe_pall(head);
	if (function.f == f_pint)
		status = exe_pint(head, lin);
	if (function.f == f_pop)
		status = exe_pop(head, lin);
	if (function.f == f_swap)
		status = exe_swap(head, lin);
	if (function.f == f_add)
		status = exe_add(head, lin);
	if (function.f == f_nop)
		status = exe_nop(head, lin);
	return (status);

}
