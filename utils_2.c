#include "push_swap.h"

int check_duplicate (t_stack *top)
{
    t_stack *temp_1;
    t_stack *temp_2;

    temp_1 = top;
    while (temp_1 != NULL)
    {
        temp_2 = temp_1->next;
        while (temp_2 != NULL)
        {
            if (temp_2->data == temp_1->data)
                return (0);
            temp_2 = temp_2->next;
        }
        temp_2 = NULL;
        temp_1 = temp_1->next;
    }
    return (1);
}

void create_stack (t_stack **top, int argc, char *argv[])
{
    t_stack *A;
    int i;
    int indx;

    i = 2;
    indx = 0;
    A = NULL;

    A = create_node (atoi(argv[1]), indx++);
    *top = A;
    while (i <= (argc - 1))
    {
        push_elm (top, create_node (atoi(argv[i++]), indx++));
    }

}

int check_if_sorted (t_stack *stack)
{
    int checker;
    t_stack *temp;
    
    checker = 0;
    temp = stack;
    while (temp != NULL)
    {
        if (temp->data < checker)
            return (0);
        checker = temp->data;
        temp = temp->next;
    }
    write (1, "stack is sorted\n", 17);
    exit (0);
}

int stack_length (t_stack *stack)
{
    t_stack *temp;
    int len;

    temp = stack;
    len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return (len);
}

int stack_max (t_stack *stack)
{
    int max;
    t_stack *temp;

    temp = stack;
    max = 0;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return (max);
}

