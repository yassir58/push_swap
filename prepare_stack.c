/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:05:05 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 13:08:57 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_len(t_stack **top)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = *top;
	while (tmp)
	{
		if (tmp->lis == 0)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

void	prepare_stack(t_stack **stack)
{
	find_lis (stack);
	mark_elements (get_pos (stack), stack);
}

void	move_non_lis(t_stack **A, t_stack **B)
{
	t_stack	*tmp_a;
	int		len;

	tmp_a = *A;
	len = count_len (A);
	while (tmp_a && len)
	{
		if (tmp_a->lis == 0)
		{
			push_element (A, B, 'b');
			len--;
		}
		else
			rotate_stack (A, 'a');
		tmp_a = *A;
	}
}
