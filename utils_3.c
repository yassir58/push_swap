/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:16:19 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 13:26:49 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_elm_top(t_stack **stack, int elm_indx)
{
	int	i ;
	int	mid_indx;

	i = 0;
	mid_indx = stack_length (*stack) / 2;
	if ((elm_indx) <= mid_indx)
	{
		i = elm_indx;
		while (i--)
			rotate_stack (stack, 'a');
	}
	else
	{
		i = stack_length (*stack) - elm_indx;
		while (i--)
			r_rotate_stack (stack, 'a');
	}
}

int	*check_position(t_stack **stack, int elm_indx)
{
	int	*elm_info;
	int	mid_indx;

	elm_info = malloc (sizeof (int) * 2);
	mid_indx = stack_length (*stack) / 2;
	if (elm_indx <= mid_indx)
	{
		elm_info[0] = elm_indx;
		elm_info[1] = 0;
	}
	else
	{
		elm_info[0] = stack_length (*stack) - elm_indx;
		elm_info[1] = 1;
	}
	return (elm_info);
}

int	stack_min(t_stack *stack)
{
	int		min;
	t_stack	*temp;

	temp = stack;
	min = stack_max (stack);
	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	get_elm_indx(t_stack **stack, int elm)
{
	t_stack	*temp;
	int		indx;

	indx = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->data == elm)
			return (indx);
		temp = temp->next;
		indx++;
	}
	return (0);
}
