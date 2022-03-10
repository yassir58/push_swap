#include "push_swap.h"


void rotate_r (t_stack **A, t_stack **B)
{
    if (*A && *B)
    rotate_stack (A, '0');
    rotate_stack (B, '0');
    write (1, "rr\n",3);
}

void r_rotate_stack (t_stack **stack, char c)
{
    t_stack *temp;

    if (*stack != NULL)
    {
        temp = *stack;
        while (temp)
        {
            if (temp->next->next == NULL)
                break;
            temp = temp->next;
        }
        push_elm (stack, temp->next);
        temp->next = NULL;
        if (c == 'a')
            write (1, "rra\n", 4);
        else if (c == 'b')
            write (1, "rrb\n", 4);
    }
}



void r_rotate_r (t_stack **A, t_stack **B)
{
    if (*A && *B)
    {
        r_rotate_stack (A, '0');
        r_rotate_stack (B, '0');
        write (1, "rrr\n",4);
    }
}