#include "main.h"
/**
 *
 *
 *
 */
int exe_pall(stack_t **head)
{
	if (*head == NULL)
		return (-1);
	else
		f_pall(head, 2);
}
/**
 *
 *
 *
 */
int exe_push(instruction_t function, char *integer, stack_t **head, unsigned int lin)
{
	int status = 0, num = 0;
	char err[20];

	status = isnum(integer);
	
	if (status == -1)
	{
		sprintf(err, "%d", lin);
		write(2, "L<",2);
		write(2, err, strlen(err));
		write(2,">: usage: push integer\n", 23);
		return (-1);
	}
	num = atoi(integer);
	function.f(head, num);

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
	return (status);

}
