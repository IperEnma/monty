#include "main.h"
/**
 *
 *
 *
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
        stack_t *aux = *stack;

        while (aux)
        {
                printf("%d\n", aux->n);
                aux = aux->next;
        }
}
/**
 *
 *
 *
 */
void f_push(stack_t **stack, unsigned int line_number)
{
        stack_t *new = NULL;

        new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                write(2, "Error: malloc failed", 21);
                exit (EXIT_FAILURE);
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

