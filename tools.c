#include "main.h"
/**
 *
 *
 */
void freelist(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}
/**
 *
 *
 *
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

