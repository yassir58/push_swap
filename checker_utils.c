#include "push_swap.h"

int found_elm (char *instr[], char *ins)
{
    int i = 0;

    while (instr[i])
    {
        if (strcmp(instr[i], ins) == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_valid_instr(char  *arg)
{
    char *instr[] = {"sa\n" , "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n","rra\n","rrb\n", "rrr\n", "\n",  NULL};
    if (found_elm (instr, arg) == 0)
        return (0);
    return (1);
}


void valid_instructions (char *arg, t_stack *A, t_stack *B)
{
    if (!check_valid_instr (arg))
    {
        printf ("Error! Invalid instructions\n");
        free_all (A, B);
        exit (1);
    }
}
int check_if_sorted_checker (t_stack *stack)
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
    write (1, "OK\n", 3);
    write (1, "stack is sorted\n", 17);
    return (1);
}

void free_all (t_stack *A, t_stack *B)
{
    free_stack (&A);
    free_stack (&B);
    free (A);
    free (B);
}