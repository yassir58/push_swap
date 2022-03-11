#include "push_swap.h"




int main (int argc, char *argv [])
{
    t_stack *top;
    t_stack *B;
    char **vector;

    B = NULL;
    top = NULL;
    vector = NULL;
    vector = process_args (argc, argv);
    // testing
    if (!vector)
        return (1);
    check_for_valid_input (vector_size (vector), vector);
    create_stack (&top, vector);
    check_for_duplicate (top);
    check_if_sorted (top, B);
    prepare_stack (&top);
    move_non_lis (&top, &B);
    sort_stack (&top, &B); 
    free_stack (&top);
    free_stack (&B);
    free (top);
    free (B);
    free_tab (vector);
    return (0);
}