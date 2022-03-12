/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:43:11 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 19:47:26 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	apply_p_instr(t_stack **A, t_stack **B, char *instr)
{
	if (ft_strcmp (instr, "pa\n") == 0)
		push_element (A, B, 'a');
	else if (ft_strcmp (instr, "pb\n") == 0)
		push_element (A, B, 'b');
	else
		return (1) ;
	return (0);
}

int	apply_r_instr(t_stack **A, t_stack **B, char *instr)
{
	if (ft_strcmp (instr, "ra\n") == 0)
		rotate_stack (A, 'a');
	else if (ft_strcmp (instr, "rb\n") == 0)
		rotate_stack (B, 'b');
	else if (strcmp (instr, "rra\n") == 0)
		r_rotate_stack (A, 'a');
	else if (ft_strcmp (instr, "rrb\n") == 0)
		r_rotate_stack (B, 'b');
	else if (ft_strcmp (instr, "rr\n") == 0)
		rotate_r (A, B);
	else if (ft_strcmp (instr, "rrr\n") == 0)
		r_rotate_r (A, B);
	else
		return  (1) ;
	return (0);
}

int	apply_s_instr(t_stack **A, t_stack **B, char *instr)
{
	if (ft_strcmp (instr, "sa\n") == 0)
		swap_element (A, 'a');
	else if (ft_strcmp (instr, "sb\n") == 0)
		swap_element (B, 'b');
	else if (ft_strcmp (instr, "ss\n") == 0)
		swap_s (A, B);
	else
		return (1);
	return (0);
}

int	check_function(t_stack *a_top, t_stack *b_top)
{
	char	*str;
	int err ;

	str = get_next_line (0);
	err = 0;
	while (str)
	{
		if (str[0] == 's')
			err = apply_s_instr (&a_top, &b_top, str);
		else if (str[0] == 'p')
			err = apply_p_instr (&a_top, &b_top, str);
		else if (str[0] == 'r')
			err = apply_r_instr (&a_top, &b_top, str);
		else
			err = 1;
		if (err == 1)
			break ;	
		free (str);
		str = get_next_line (0);
	}
	if (err == 1)
		free (str);
	return (err);
}

int	main(int argc, char *argv [])
{
	t_stack	*a_top;
	t_stack	*b_top;
	char	**vector;
	int		err;

	err = 2;
	b_top = NULL;
	a_top = NULL;
	vector = NULL;
	vector = process_args (argc, argv);
	if (!vector)
		return (1);
	check_for_valid_input (vector_size(vector), vector);
	create_stack (&a_top, vector);
	check_for_duplicate (a_top);
	if (!check_if_sorted (a_top))
		err = check_function (a_top, b_top);
	if (err == 1)
		write (1, "Error, Invalid Instruction\n", 27);
	if (!check_if_sorted (a_top) && err == 0)
		write (1, "KO\n", 3);
	else if (err == 0)
		write (1, "OK\n", 3);
	free_all (a_top, b_top);
	free_tab (vector);
	return (0);
}
