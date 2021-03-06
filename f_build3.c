#include "monty.h"
/**
 * f_mod - mods the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int mod = 0;

	(void)line_number;
	mod = aux->n;
	aux = aux->next;
	mod = aux->n % mod;
	f_pop(stack, mod);
	f_pop(stack, mod);
	f_push(stack, mod);
}
/**
 * f_pchar - prints the value at the top of the stack as char
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	putchar(aux->n);
	putchar('\n');
}
