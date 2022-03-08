#include "push_swap.h"

int max_elm (int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

void free_stack (t_stack **stack)
{
    t_stack *elm;
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        elm = pop_elm (stack);
        free (elm);
        temp = *stack;
    }
}

int *convert_to_array (t_stack **stack, int size)
{
    int i ;
    t_stack *temp;
    int *arr;

    temp = *stack;
    i = 0;
    arr = (int *) malloc (sizeof (int) * size);
    if (!arr)
        return (NULL);
    while (temp)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    return (arr);
}

int *init_arr (int *arr, int c, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        arr[i++] = c;
    }
    return (arr);
}




int arr_max (int *arr, int size)
{
    int temp;
    int i;

    i = 0;
    temp = 0;
    while (i < size)
    {
        if (arr[i] > temp)
            temp = arr[i];
        i++;
    }
    return (temp);
}


