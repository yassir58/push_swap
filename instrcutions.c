#include "push_swap.h"


void swap_element (t_stack **stack, char c)
{
    t_stack next;
    t_stack top;

    if (*stack != NULL)
    {
        top = pop_elm (stack);
        next = pop_elm (stack);
        push_elm (stack, top.data);
        push_elm (stack, next.data);
        if (c == 'a')
            write (1, "sa\n", 4);
        else if (c == 'b')
            write (1, "sb\n", 4);
    }
}
// void swap_a (t_stack **A)
// {
//     t_stack next;
//     t_stack top;

//     if (A != NULL)
//     {
//         top = pop_elm (A);
//         next = pop_elm (A);
//         push_elm (A,top.data);
//         push_elm (A,next.data);
//         write (1, "sa\n", 4);
//     }
// }

// void swap_b (t_stack **B)
// {
//     t_stack next;
//     t_stack top;

//     if (B != NULL)
//     {
//         top = pop_elm (B);
//         next = pop_elm (B);
//         push_elm (B,top.data);
//         push_elm (B,next.data);
//         write (1, "sb\n", 4);
//     }
// }

void swap_s (t_stack **A, t_stack **B)
{
   swap_element (A, 'a');
   swap_element (B, 'b');
    write (1, "ss\n",4);
}

int push_element (t_stack **A, t_stack **B, char c)
{
      t_stack temp;
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
        push_elm (push_to, temp.data);
    }
    return (stack_length (*tmp_stack));
}
/*
int push_a(t_stack **A, t_stack **B)
{
    t_stack temp;

    if (*B != NULL)
    {
        temp = pop_elm (B);
        push_elm (A,temp.data);
        write (1, "pa\n",4);
    }
    return (stack_length (*B));
}
int push_b (t_stack **A, t_stack **B)
{
     t_stack temp;

    if (*A != NULL)
    {
        temp = pop_elm (A);
        push_elm (B,temp.data);
        write (1, "pa\n",4);
    }
     return (stack_length (*A));
}*/
// void rotate_a (t_stack **A)
// {
//     t_stack *temp;
//     t_stack top;

//     temp = NULL;
//     if (*A != NULL)
//     {
//         top = pop_elm (A);
//         temp = *A;
//         while (temp->next)
//         {
//             temp = temp->next;
//         }
//         temp->next = malloc (sizeof (t_stack));
//         temp->next->data = top.data;
//         temp->next->next = NULL;
//         write (1, "ra\n", 4);
//     }
// }

void rotate_stack (t_stack **stack, char c)
{

    t_stack *temp;
    t_stack top;

    temp = NULL;
    if (*stack != NULL)
    {
        top = pop_elm (stack);
        temp = *stack;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = malloc (sizeof (t_stack));
        temp->next->data = top.data;
        temp->next->next = NULL;
        if (c == 'a')
            write (1, "ra\n", 4);
        else if (c == 'b')
            write (1, "rb\n",4);
    }
}