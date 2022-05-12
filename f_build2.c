#include "monty.h"
/**
 * f_add - adds the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int add = 0;

	(void)line_number;
	add = aux->n;
	aux = aux->next;
	add = add + aux->n;
	f_pop(stack, add);
	f_pop(stack, add);
	f_push(stack, add);
}
/**
 * f_sub - subs the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int sub = 0;

	(void)line_number;
	sub = aux->n;
	aux = aux->next;
	sub = aux->n - sub;
	f_pop(stack, sub);
	f_pop(stack, sub);
	f_push(stack, sub);
}
/**
 * f_div - divs the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int div = 0;

	(void)line_number;
	div = aux->n;
	aux = aux->next;
	div = aux->n / div;
	f_pop(stack, div);
	f_pop(stack, div);
	f_push(stack, div);
}
/**
 * f_mul - mul the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int mul = 0;

	(void)line_number;
	mul = aux->n;
	aux = aux->next;
	mul = aux->n * mul;
	f_pop(stack, mul);
	f_pop(stack, mul);
	f_push(stack, mul);
}
/**
 * f_nop - doesn’t do anything
 * @stack: firts node of the stack
 * @line_number: number line
 * Return: void
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
