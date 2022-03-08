#include "push_swap.h"


void rotate_r (t_stack **A, t_stack **B)
{
    if (*A && *B)
    rotate_stack (A, 'a');
    rotate_stack (B, 'b');
    write (1, "rr\n",4);
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
            write (1, "rra\n", 5);
        else if (c == 'b')
            write (1, "rrb\n", 5);
    }
}



void r_rotate_r (t_stack **A, t_stack **B)
{
    if (*A && *B)
    {
        r_rotate_stack (A, 'a');
        r_rotate_stack (B, 'b');
        write (1, "rrr\n",5);
    }
}