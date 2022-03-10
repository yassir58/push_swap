
#include "push_swap.h"


pos *find_best (t_stack **A, t_stack **B, int elm)
{
    t_stack *top;
    int *a_pos;
    int *b_pos;
    pos *elm_pos;

    top = *A;
    // print_stack (top);
    // print_stack (*B);
    // printf ("*******************************************************************************\n");
    // printf ("elm ==> %d \n", elm);
    elm_pos = init_pos (A, B);
    if (elm > stack_max (*A) || elm < stack_min (*A))
    {
        a_pos = check_position (A, get_elm_indx (A, stack_min (*A)));
        b_pos = check_position (B, get_elm_indx (B, elm));
        // printf (" (case 1) --> elm |%d| a pos |%d| b pos |%d| \n", elm , a_pos[0], b_pos[0]);
        return (update_pos (elm_pos, a_pos, b_pos));
    }
    if (last_check (A, elm))
    {
        elm_pos->a_pos = 0;
        elm_pos->a_rotate = 0;
        b_pos = check_position (B, get_elm_indx (B, elm));
        elm_pos->b_pos = b_pos[0];
        elm_pos->b_rotate =b_pos[1];
        //  printf (" (case 2) --> elm |%d| a pos |%d| b pos |%d| \n", elm, elm_pos->a_pos, elm_pos->b_pos);
        return (elm_pos);
    }
    while (top)
    {
        if (elm > top->data && elm < top->next->data)
        {
            a_pos = check_position (A, get_elm_indx (A, top->next->data));
            b_pos = check_position (B, get_elm_indx (B, elm));
            // printf (" (case 3) --> elm |%d| a pos |%d| b pos |%d| \n", elm , a_pos[0], b_pos[0]);
            // printf (" prev %d next %d \n", top->data, top->next->data);
            return (update_pos (elm_pos, a_pos, b_pos));
        }
        top = top->next ;
    }
    return (elm_pos);    
}


pos* chose_best_elm (pos *elm_pos, pos *min)
{
    
    if (elm_pos->a_rotate == elm_pos->b_rotate)
    {
        if (max_elm (elm_pos->a_pos, elm_pos->b_pos) < (min->a_pos + min->b_pos))
            return (elm_pos);
    }
    if ((elm_pos->a_pos + elm_pos->b_pos)  < (min->a_pos + min->b_pos))
        return (elm_pos);
    return (min);
}

pos *calculate_best_elm (t_stack **A, t_stack **B)
{
    // t_stack *temp_a;
    t_stack *temp_b;
    pos *tmp;
    pos *min;
        
    temp_b = *B;
    // temp_a = *A;
    tmp = init_pos (A, B);
    min = init_pos (A, B);
    while (temp_b)
    {
        tmp = find_best (A, B, temp_b->data);
        min = chose_best_elm (tmp, min);
        // printf ("--> elm |%d| a pos |%d| b pos |%d| \n", temp_b->data , tmp->a_pos, tmp->b_pos);
        temp_b = temp_b->next;
    }
    return (min);
}

void sort_stack (t_stack **A, t_stack **B)
{
    int size;
    pos *pos ;
    
    size = stack_length (*B);
    while (size)
    {
        pos = calculate_best_elm (A, B);
        // printf ("__________________________________________________________\n");
        // printf ("||pos a %d || pos b %d || a rotate %d || b rotate %d ||\n", pos->a_pos, pos->b_pos, pos->a_rotate, pos->b_rotate);
        // printf ("__________________________________________________________\n");
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