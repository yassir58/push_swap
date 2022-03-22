/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:43:11 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 17:16:54 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

char	**check_function(void)
{
	char	*str;
	char	**instr_tab;

	str = get_next_line (0);
	instr_tab = NULL;
	while (str)
	{
		if (valid_instructions (str))
			instr_tab = join_vector (instr_tab, one_word_tab (str));
		else if (!ft_strcmp (str, "\n"))
		{
			free (str);
			return (instr_tab);
		}
		else
			return (instruction_err (str, instr_tab));
		free (str);
		str = get_next_line (0);
	}
	return (instr_tab);
}

int	main(int argc, char *argv [])
{
	t_stack	*a_top;
	t_stack	*b_top;
	char	**vector;
	char	**instr;

	b_top = NULL;
	a_top = NULL;
	vector = NULL;
	vector = process_args (argc, argv);
	if (!vector)
		return (1);
	init_stack (&a_top, vector);
	if (check_if_sorted (a_top, b_top))
	{
		write (1, "OK\n", 3);
		clean_function (a_top, b_top, vector);
		exit (0);
	}
	instr = check_function ();
	if (instr)
	{
		sort_test (&a_top, &b_top, instr);
		if (check_if_sorted (a_top, b_top))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
	free_tab (instr);
	clean_function (a_top, b_top, vector); 
	return (0);
}