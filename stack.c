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
    t_stack *temp;
    prepare_stack (&top);
    move_non_lis (&top, &B);
    temp = top;
    while (temp)
    {
        printf ("%d ", temp->data);
        temp = temp->next; 
    }
    printf ("\n");
    printf ("printing stack B:\n");
    temp = B;
    while (temp)
    {
        printf ("%d ", temp->data);
        temp = temp->next; 
    }
    printf ("\n");
    printf ("sorting stack ..\n");
    pos *test;

    test = calculate_best_elm (&top, &B);

    printf ("a position : |%d|\n", test->a_pos);
    printf ("b position :  |%d|\n", test->b_pos);
    printf ("a rotate : |%d|\n", test->a_rotate);
    printf ("b rotate : |%d|\n", test->b_rotate);
    free (test);
    //sort_stack (&top, &B);
    // temp = top;
    // while (temp)
    // {
    //     printf ("%d ", temp->data);
    //     temp = temp->next; 
    // }
    // printf ("\n");
    // printf ("printing stack B:\n");
    // temp = B;
    // while (temp)
    // {
    //     printf ("%d ", temp->data);
    //     temp = temp->next; 
    // }
    // printf ("\n");
    


    free_stack (&top);
    free_stack (&B);
    free (top);
    free (B);
    //free (pos);

    return (0);
}