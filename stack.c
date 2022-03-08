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

    int len = stack_length(top);
   
    int *arr;
    t_stack *temp;
    arr = convert_to_array (&top, len);
    t_stack *temp_stack;
    temp_stack = copy_stack (arr, len); 
    prepare_stack (&temp_stack);
    free (arr);
    arr = convert_to_array (&temp_stack, len);
    move_non_lis (&top, &B, arr, len);
    sort_stack (&top, &B);
    temp =top;
    while (temp)
    {
         
        printf ("%d ", temp->data);
        temp = temp->next; 
    }
    printf ("\n");
    printf ("printing stack B:\n");
    temp =B;
    while (temp)
    {
       
        printf ("%d ", temp->data);
        temp = temp->next; 
    }
    printf ("\n");
    

    free (arr);
    free_stack (&top);
    free_stack (&B);
    free_stack (&temp_stack);
    free (top);
    free (B);
    free (temp_stack);
    //free (pos);

    return (0);
}