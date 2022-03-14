/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:02:32 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 12:50:56 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spec_rotate(t_stack **stack, int size, int rotate, int c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (rotate == 0)
			rotate_stack (stack, c);
		else
			r_rotate_stack (stack, c);
		i++;
	}
}

void	r_spec_rotate(t_stack **A, t_stack **B, int size, int rotate)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (rotate == 0)
			rotate_r (A, B);
		else
			r_rotate_r (A, B);
		i++;
	}
}

void	smart_rotate(t_pos *elm_pos, t_stack **A, t_stack **B)
{
	if (elm_pos->a_pos == elm_pos->b_pos
		&& elm_pos->a_rotate == elm_pos->b_rotate)
		r_spec_rotate (A, B, elm_pos->a_pos, elm_pos->a_rotate);
	else if ((elm_pos->a_pos != 0 && elm_pos->a_pos != 0)
		&& (elm_pos->a_rotate == elm_pos->b_rotate))
		diff_rotate (elm_pos, A, B);
	else
	{
		spec_rotate (A, elm_pos->a_pos, elm_pos->a_rotate, 'a');
		spec_rotate (B, elm_pos->b_pos, elm_pos->b_rotate, 'b');
	}
}

int	last_check(t_stack **A, int elm)
{
	t_stack	*tmp_a;
	int		a_top;
	int		a_tail;

	tmp_a = *A;
	a_top = tmp_a->data;
	while (tmp_a)
	{
		a_tail = tmp_a->data;
		tmp_a = tmp_a->next;
	}
	if (elm < a_top && elm > a_tail)
		return (1);
	return (0);
}

t_pos	*set_last_pos(t_pos *elm_pos, t_stack **B, int elm)
{
	int	*b_pos;

	b_pos = check_position (B, get_elm_indx(B, elm));
	elm_pos->a_pos = 0;
	elm_pos->b_pos = b_pos[0];
	elm_pos->a_rotate = 0;
	elm_pos->b_rotate = b_pos[1];
	free (b_pos);
	return (elm_pos);
}
