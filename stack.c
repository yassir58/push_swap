#include "push_swap.h"




void set_element (t_stack **top, int data)
{
    t_stack *temp;
    if (*top == NULL)
    {
        *top = malloc (sizeof (t_stack));
    }
    temp = *top;
    temp->data = data;
    temp->next = NULL;
}





int main (int argc, char *argv [])
{
    t_stack *top;
    t_stack *B;

    B = NULL;
    top = NULL;
    // testing

    check_for_valid_input (argc, argv);
    create_stack (&top, argc, argv);
    check_for_duplicate (top);
    check_if_sorted (top);
    prepare_stack (&top);
    move_non_lis (&top, &B);
    sort_stack (&top, &B);
    // check_if_sorted (top);


    
    free_stack (&top);
    free_stack (&B);
    free (top);
    free (B);
    //free (pos);

    return (0);
}