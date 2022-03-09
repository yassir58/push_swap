#include "push_swap.h"

void position_elm_top (t_stack **stack, int elm_indx)
{
    int i ;

    i = 0;
    int mid_indx = stack_length (*stack) / 2;
    if ((elm_indx) <= mid_indx)
    {
        i = elm_indx;
        while (i--)
            rotate_stack (stack, 'a');
    }
    else
    {
        i = stack_length (*stack) - elm_indx;
        while (i--)
            r_rotate_stack (stack, 'a');
    }
}

int *check_position (t_stack **stack, int elm_indx)
{
    int *elm_info;
    int mid_indx;


    elm_info = malloc (sizeof (int) * 2);
    mid_indx = stack_length (*stack) / 2;
    if (elm_indx <= mid_indx)
    {
        //rotate
        elm_info[0] = elm_indx;
        elm_info[1] = 0;
    }
    else
    {
        //reverse rotate
        elm_info[0] = stack_length (*stack) - elm_indx;
        elm_info[1] = 1;
    }
    return (elm_info);
}

int stack_min (t_stack *stack)
{
    int min;
    t_stack *temp;

    temp = stack;
    min = stack_max (stack);
    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return (min);
}

int stack_empty (t_stack *stack)
{
    if (stack_length (stack) == 0)
        return (1);
    return (0);
}

int get_elm_indx (t_stack **stack, int elm)
{
    t_stack *temp;
    int indx = 0;

    temp = *stack;
    while (temp)
    {
        if (temp->data == elm)
            return (indx);
        temp = temp->next;
        indx++;
    }
    return (0);
}

t_stack *create_node (int data)
{
    t_stack *node;

    node = malloc (sizeof (t_stack));
    node->data = data;
    node->lis = 0;
    node->indx = -1;
    node->len = 1;
    node->next = NULL;
    return (node);
}
