#include "monty.h"
/**
 * freelist - clean the list
 * @head: first node of the stack
 * Return: void
 */
void freelist(stack_t *head)
{
	stack_t *aux;

	if (head == NULL)
		return;
	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
/**
 * lenstack - length of the list
 * @head: first node of the list
 * Return: i
 */
int lenstack(stack_t **head)
{
	int i = 0;
	stack_t *aux = *head;

	for (i = 0; aux; i++)
		aux = aux->next;
	return (i);
}
/**
 * isnum - check that token 2 is integer
 * @integer: token 2
 * Return: 0 success or -1 if fail
 */
int isnum(char *integer)
{
	int i = 0;

	for (i = 0; integer[i]; i++)
	{
		if (integer[i] < 48 || integer[i] > 57)
			return (-1);
	}
	return (0);
}

