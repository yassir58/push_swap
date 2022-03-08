#include "push_swap.h"



t_stack *copy_stack (int *arr, int size)
{
    t_stack *temp_stack;
    t_stack *node;
    
    temp_stack = create_node (arr[size-- - 1], 0);
    while (size--)
    {
        node = create_node (arr[size], 0);
        push_elm (&temp_stack, node);
    }
    return (temp_stack);
}

void  prepare_stack(t_stack **stack)
{
    int min;
    int min_indx;

    min = stack_min (*stack);
    min_indx = get_elm_indx (stack, min);
    position_elm_top (stack, min_indx);
}

void move_non_lis (t_stack **A, t_stack **B,int *arr, int size)
{
    int *indx_arr;
    int *len_arr;
    int *lis;
    int max = 0;


    indx_arr  = find_indx_arr (size);
    len_arr = test_len_arr (arr, size, &indx_arr);
    max = arr_max (len_arr, size);
    lis = construct_lis (arr, indx_arr, len_arr, size, max);
    extract_elm (A, lis, max);
    move_non_lis_to_B (A, B); 
   
    free (lis);
    free (len_arr);
    free (indx_arr);
}