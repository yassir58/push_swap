#include "push_swap.h"



int valid_instructions (char *str)
{
    char **instr;
    int i;

    i = 0;
    instr  = ft_split ("sa\n sb\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n ss\n rrr\n", ' ');
    while (instr[i])
    {
        if (ft_strcmp (instr[i], str) == 0)
		{
			free_tab (instr);
			return (1);
		}
        i++;   
    }
	free_tab (instr);
    return (0);
}

void *instruction_err (char *str, char **tab)
{
	free (str);
    if (tab != NULL)
        free_tab (tab);
    write (2, "Invalid instruction !\n", 22);
    return (NULL);
}


void sort_test (t_stack **a_top, t_stack **b_top, char **instr)
{
        int i = 0;
		while (instr[i])
		{
			if (!ft_strcmp (instr[i], "pa\n"))
				push_element (a_top, b_top, 'a');
			else if (!ft_strcmp (instr[i], "pb\n"))
				push_element (a_top, b_top, 'b');
			else if (!ft_strcmp (instr[i], "sa\n"))
				swap_element (a_top, 'a');
			else if (!ft_strcmp (instr[i], "sb\n"))
				swap_element (b_top, 'b');
			else if (!ft_strcmp (instr[i], "ss\n"))
				swap_s (a_top, b_top);
            else 
                rotate_instructions (a_top, b_top, instr[i]);
			i++;
		}
}


void rotate_instructions (t_stack **a_top, t_stack **b_top, char *instr)
{
        if (!ft_strcmp (instr, "ra\n"))
			rotate_stack (a_top, 'a');
		else if (!ft_strcmp (instr, "rb\n"))
			rotate_stack (b_top, 'b');
		else if (!ft_strcmp (instr, "rr\n"))
			rotate_r (a_top, b_top);
		else if (!ft_strcmp (instr, "rra\n"))
			r_rotate_stack (a_top, 'a');
		else if (!ft_strcmp (instr, "rrb\n"))
			r_rotate_stack (b_top, 'b');
		else if (!ft_strcmp (instr, "rrr\n"))
			r_rotate_r (a_top, b_top);
}
