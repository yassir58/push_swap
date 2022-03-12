#include "push_swap.h"

void sort_all (t_stack **a_top, t_stack **b_top)
{
    prepare_stack (a_top);
    move_non_lis (a_top, b_top);
    sort_stack (a_top, b_top);
}

void sort_3 (t_stack **a_top)
{
    t_stack *tmp_a;

    tmp_a = *a_top;
    if (tmp_a->data < tmp_a->next->next->data)
    {
        if (tmp_a->next->data < tmp_a->data)
            swap_element (a_top, 'a');
        if (tmp_a->next->data > tmp_a->next->next->data)
        {
            swap_element (a_top, 'a');
            rotate_stack (a_top, 'a');
        }
    }
    else
    {
        if (tmp_a->data > tmp_a->next->data)
        {
            if (tmp_a->next->data < tmp_a->next->next->data)
                rotate_stack (a_top,'a');
            else
            {
                 swap_element (a_top, 'a');
                r_rotate_stack (a_top, 'a');
            }
        }
        else
            r_rotate_stack (a_top, 'a');
    }
}

void sort_5 (t_stack **a_top, t_stack **b_top)
{
    int n;

    n = 2;
    while (n--)
    {
        position_elm_top(a_top, get_elm_indx (a_top, stack_min (*a_top)));
        push_element (a_top, b_top, 'b');
    }
    sort_3 (a_top);
    push_element (a_top, b_top, 'a');
    push_element (a_top, b_top, 'a');
}

int main (int argc, char *argv [])
{
    t_stack *a_top;
    t_stack *b_top;
    char **vector;

    b_top = NULL;
    a_top = NULL;
    vector = NULL;
    vector = process_args (argc, argv);
    if (!vector)
        return (1);
    check_for_valid_input (vector_size (vector), vector);
    create_stack (&a_top, vector);
    check_for_duplicate (a_top);
    check_if_sorted (a_top);
    if (vector_size (vector) == 3)
        sort_3 (&a_top);
    else if (vector_size (vector) == 5)
         sort_5 (&a_top, &b_top);
    else
        sort_all (&a_top, &b_top);
    free_all (a_top, b_top);
    free_tab (vector);
    return (0);
}