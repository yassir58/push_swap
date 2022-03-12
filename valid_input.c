#include "push_swap.h"


void check_for_valid_input (int argc, char *argv[])
{
    if (argc == 1 || !valid_input (argv))
    {
        write (2, "Error! Invalid Input\n", 22);
        exit (0);
    }
}

void check_for_duplicate (t_stack *stack)
{
    if (!check_duplicate (stack))
    {
        write (2, "Duplicte element found\n", 24);
        exit (0);
    }
}
