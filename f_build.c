#include "monty.h"
/**
 * f_pop - removes the top element of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;

	*stack = (*stack)->next;
	free(aux);
}
/**
 * f_pint - prints the value at the top of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	printf("%d\n", aux->n);
}
/**
 * f_pall - prints all the values on the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	(void)line_number;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
/**
 * f_push - pushes an element to the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		write(2, "Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
/**
 * f_swap - swaps the top two elements of the stack
 * @stack: first node of the stack
 * @line_number: number line
 * Return: void
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int temp = 0;

	(void)line_number;
	aux = aux->next;
	temp = (*stack)->n;
	(*stack)->n = aux->n;
	aux->n = temp;
}
