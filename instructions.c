#include "push_swap.h"


void swap_element (t_stack **stack, char c)
{
    t_stack *next;
    t_stack *top;

    if (*stack != NULL)
    {
        top = pop_elm (stack);
        next = pop_elm (stack);
        push_elm (stack, top);
        push_elm (stack, next);
        if (c == 'a')
            write (1, "sa\n", 4);
        else if (c == 'b')
            write (1, "sb\n", 4);
    }
}

void swap_s (t_stack **A, t_stack **B)
{
   swap_element (A, 'a');
   swap_element (B, 'b');
    write (1, "ss\n",4);
}

int push_element (t_stack **A, t_stack **B, char c)
{
      t_stack *temp;
      t_stack **tmp_stack;
      t_stack **push_to;

      if (c == 'a')
      {
          push_to = A;
          tmp_stack = B;
          write (1, "pa\n",4);
      }
      else 
      {
          push_to = B;
          tmp_stack = A;
          write (1, "pb\n",4);
      }
    if (*tmp_stack)
    {
        temp = pop_elm (tmp_stack);
        push_elm (push_to, temp);
    }
    return (stack_length (*tmp_stack));
}

void rotate_stack (t_stack **stack, char c)
{

    t_stack *temp;
    t_stack *top;

    temp = NULL;
    if (*stack != NULL)
    {
        top = pop_elm (stack);
        temp = *stack;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = top;
        top->next = NULL;
        if (c == 'a')
            write (1, "ra\n", 4);
        else if (c == 'b')
            write (1, "rb\n",4);
    }
}