#include "main.h"
/**
 *
 *
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int add = 0;
	
	add = aux->n;
	aux = aux->next;
	add = add + aux->n;
	f_pop(stack, add);
	f_pop(stack, add);
	f_push(stack, add);
}
/**
 *
 *
 *
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void *)stack;
	(void)line_number;
}
