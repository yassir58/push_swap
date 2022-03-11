#include "push_swap.h"


int *best_elm_to_extract (t_stack **A)
{
    int *temp;
    int *pos;
    t_stack *temp_a;

    temp = malloc (sizeof (int) * 2);
    temp[0] = stack_length (*A);
    temp[1] = 0;
    temp_a = *A;
    while (temp_a)
    {
        if (temp_a->lis != 1)
        {
            pos = check_position (A, get_elm_indx (A, temp_a->data));
            if (pos[0] < temp[0])
            {
                 temp[0] = pos[0];
                 temp[1] = pos [1];
            }
             free (pos);
        }
        temp_a = temp_a->next;
    }
    
    return (temp);
}

int get_non_lis_count (t_stack **A)
{
    int count;
    t_stack *temp;

    count = 0;
    temp  = *A;
    while (temp)
    {
        if (temp->lis != 1)
            count++;
        temp = temp->next;
    }
    return (count);
}

void move_elm (t_stack **A, t_stack **B)
{
    int *best;
    int i;

    i = 0;
    best = best_elm_to_extract (A);
    while (i < best[0])
    {
        if (best[1] == 0)
            rotate_stack (A, 'a');
        else
            r_rotate_stack (A, 'a');
        i++;
    }
    push_element (A, B, 'b');
    free (best);
}


void move_non_lis_to_B (t_stack **A, t_stack **B)
{
    int non_lis_count = 0;

    non_lis_count = get_non_lis_count (A);
    while (non_lis_count)
    {
        move_elm (A, B);
        non_lis_count = get_non_lis_count (A);
    }
}


/// best allocated