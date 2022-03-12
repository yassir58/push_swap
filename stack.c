#include "push_swap.h"

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
    prepare_stack (&a_top);
    move_non_lis (&a_top, &b_top);
    sort_stack (&a_top, &b_top); 
    free_all (a_top, b_top);
    free_tab (vector);
    return (0);
}