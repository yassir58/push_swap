/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:59 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/17 12:51:53 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_num(t_long num, t_stack **stack, char **tab)
{
	int	res;

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

void	clean_function(t_stack *a_top, t_stack *b_top, char **vector)
{
	free_all (a_top, b_top);
	free_tab (vector);
}

void *handle_err ()
{
	write (2, "Error !\n", 8);
	return (NULL);
}

int one_word (char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	if (i > 0)
		return (1);
	return (0);
}

char **one_word_tab (char *str)
{
	char **tab;
	int i;

	i = 0;
	tab = malloc (sizeof (char*) * 2);
	if (!tab)
		return (NULL);
	if (str)
		tab[i++] = ft_strdup(str);
	tab[i] = NULL;
	return (tab);
}
