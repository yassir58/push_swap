#include "push_swap.h"

int range_number (long long int num, t_stack **stack, char **tab)
{
    int res;

    if (num > _INT_MAX || num < _INT_MIN)
    {
        free_stack (stack);
        free_tab (tab); 
        write (2, "Error, Number out of range !\n", 29);
        exit (0);
    }
    res = (int)num;
    return (res);
}
