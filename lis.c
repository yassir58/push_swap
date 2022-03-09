#include "push_swap.h"

int max_elm (int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

void free_stack (t_stack **stack)
{
    t_stack *elm;
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        elm = pop_elm (stack);
        free (elm);
        temp = *stack;
    }
}




