
#include "push_swap.h"




pos *calculate_best_elm (t_stack **A, t_stack **B)
{
    t_stack *temp_a;
    t_stack *temp_b;
    pos *elm_pos;
    int *a_pos;
    int *b_pos;
        

    temp_b = *B;
    temp_a = *A;
    elm_pos = init_pos (A, B);    

    while (temp_b)
    {
        if (temp_b->data == stack_max (*B) && temp_b->data > stack_max (*A))
        {
            free (elm_pos);
            return (get_max_pos (A, B,  temp_b->data));
        }
        while (temp_a)
        {
            if (temp_a->data < temp_b->data && temp_a->next && 
            temp_a->next->data > temp_b->data)
            {
                a_pos = check_position (A,get_elm_indx (A, temp_a->next->data));
                b_pos = check_position (B, get_elm_indx (B, temp_b->data));
                if ((a_pos[0] + b_pos[0]) < (elm_pos->a_pos + elm_pos->b_pos))
                    elm_pos = update_pos (elm_pos, a_pos, b_pos);
                free (a_pos);
                free (b_pos);
            }
            temp_a = temp_a->next;
        }
        temp_b = temp_b->next;
        temp_a = *A;
        
    }
  
    return (elm_pos);
}

void sort_stack (t_stack **A, t_stack **B)
{
    int size;
    pos *pos ;
    
    size = stack_length (*B);
    while (size)
    {
        pos = calculate_best_elm (A, B);
        smart_rotate (pos, A, B);
        push_element (A,B, 'a');
        size = stack_length (*B);
        free (pos);
    }
    position_elm_top (A, get_elm_indx (A, stack_min (*A)));
}

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