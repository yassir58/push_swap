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
    char *instr[] = {"sa\n" , "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n","rra\n","rrb\n", "rrr\n", "q\n",  NULL};
    if (found_elm (instr, arg) == 0)
        return (0);
    return (1);
}


void valid_instructions (char *arg)
{
    if (check_valid_instr (arg))
        printf ("valid instructions\n");
    else 
    {
        printf ("Error! Invalid instructions\n");
        exit (1);
    }
}