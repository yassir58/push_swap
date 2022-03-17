/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:50:58 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 14:52:47 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_valid_input(int argc, char *argv[])
{
	if (argc == 1 || !valid_input (argv))
	{
		write (2, "Error! Invalid Input\n", 22);
		exit (0);
	}
}

void	check_for_duplicate(t_stack *stack, char **vector)
{
	if (!check_duplicate (stack))
	{
		write (2, "Duplicte element found\n", 24);
		free_stack(&stack);
		free_tab (vector);
		exit (0);
	}
}

void	init_stack(char **vector, t_stack *a_top)
{
	check_for_valid_input (vector_size(vector), vector);
	create_stack (&a_top, vector);
	check_for_duplicate (a_top, vector);
}

t_pos	*update_elm_pos(t_pos *elm_pos, t_pos *min)
{
	elm_pos->a_pos = min->a_pos;
	elm_pos->b_pos = min->b_pos;
	elm_pos->a_rotate = min->a_rotate;
	elm_pos->b_rotate = min->b_rotate;
	free (min);
	return (elm_pos);
}

int	*get_arr(int a, int b)
{
	int	*elm;

	elm = malloc (sizeof (int) * 2);
	if (!elm)
		return (NULL);
	elm[0] = a;
	elm[1] = b;
	return (elm);
}
