/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:09:06 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 12:40:19 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elm(t_stack **top, t_stack *node)
{
	node->next = *top;
	*top = node;
}

t_stack	*pop_elm(t_stack **top)
{
	t_stack	*temp;

	temp = *top;
	*top = temp->next;
	return (temp);
}

int	ft_isdigit(char c)
{
	if ((c >= 48 && c <= 57) || c == 45)
		return (1);
	return (0);
}

int	valid_number(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_input(char *argv [])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (!valid_number (argv[i]))
			return (0);
		i++;
	}
	return (1);
}
