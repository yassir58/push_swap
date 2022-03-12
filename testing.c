#include "push_swap.h"





void print_stack (t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    printf ("\n____________________________________________________\n");
    while (tmp)
    {
        printf ("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf ("\n____________________________________________________\n");
}