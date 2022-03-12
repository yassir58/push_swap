/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:31:20 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 13:46:27 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lis(t_stack **top)
{
	t_stack	*tmp_i;
	t_stack	*tmp_j;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = stack_length (*top);
	tmp_i = *top;
	while (i < len)
	{
		tmp_j = *top;
		while (j < i)
		{
			if (tmp_i->data > tmp_j->data && (tmp_j->len + 1) > tmp_i->len)
				set_indx_len (&tmp_i, (tmp_j->len + 1), j);
			tmp_j = tmp_j->next;
			j++;
		}
		i++;
		tmp_i = tmp_i->next;
		j = 0;
	}
}

int	get_pos(t_stack **top)
{
	int		pos;
	int		i;
	t_stack	*tmp_top;
	int		temp;

	i = 0;
	temp = 0;
	tmp_top = *top;
	while (i < stack_length (*top))
	{
		if (tmp_top->len > temp)
		{
			temp = tmp_top->len;
			pos = i;
		}
		tmp_top = tmp_top->next;
		i++;
	}
	return (pos);
}

int	get_indx(int pos, t_stack **top)
{
	t_stack	*temp;

	temp = *top;
	while (pos--)
		temp = temp->next;
	return (temp->indx);
}

void	get_elm(t_stack **top, int indx)
{
	t_stack	*temp;

	temp = *top;
	while (indx--)
		temp = temp->next;
	temp->lis = 1;
}

void	mark_elements(int pos, t_stack **top)
{
	int	pos_tmp;

	pos_tmp = pos;
	while (pos_tmp != -1)
	{
		get_elm (top, pos_tmp);
		pos_tmp = get_indx (pos_tmp, top);
	}
}
