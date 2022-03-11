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

int check_if_sorted (t_stack *stack, t_stack *stack_b)
{
    int checker;
    t_stack *temp;
    
    checker = 0;
    temp = stack;
    while (temp != NULL)
    {
        if (temp->data < checker)
            return (0);
        checker = temp->data;
        temp = temp->next;
    }
    write (1, "OK\n", 3);
    write (1, "stack is sorted\n", 17);
    free_all (stack, stack_b);
    return (1);
}
