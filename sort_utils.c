#include "push_swap.h"

pos *init_pos (t_stack **A, t_stack **B)
{
    pos *elm_pos;

    elm_pos = malloc (sizeof (pos));
    elm_pos->a_pos = stack_length (*A);
    elm_pos->b_pos = stack_length (*B);
    elm_pos->a_rotate = 0;
    elm_pos->a_rotate = 0;
    return (elm_pos);
} 

pos *update_pos (pos *elm_pos, int *temp_pos_a, int *temp_pos_b)
{
    elm_pos->a_pos = temp_pos_a[0];
    elm_pos->b_pos = temp_pos_b[0];
    elm_pos->a_rotate = temp_pos_a[1];
    elm_pos->b_rotate = temp_pos_b[1];
    free (temp_pos_a);
    free (temp_pos_b);
    return (elm_pos);
}

pos *get_max_pos (t_stack **A, t_stack **B,  int elm)
{
    int *a_pos;
    int *b_pos;

    pos *elm_pos;
    a_pos = check_position (A, get_elm_indx (A, stack_min (*A)));
    b_pos = check_position (B, get_elm_indx (B, elm));
    elm_pos = init_pos (A, B);
    elm_pos->a_pos = a_pos[0];
    elm_pos->b_pos = b_pos[0];
    elm_pos->a_rotate = a_pos[1] ;
    elm_pos->b_rotate = b_pos[1] ;

    free (a_pos);
    free (b_pos);
    return (elm_pos);
}