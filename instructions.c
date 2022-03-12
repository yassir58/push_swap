/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:24 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 13:58:38 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_element(t_stack **top, char c)
{
	t_stack	*next;
	t_stack	*elm;
	int		tmp;

	if (*top != NULL)
	{
		elm = *top;
		next = elm->next;
		tmp = elm->data;
		elm->data = next->data;
		next->data = tmp;
		if (c == 'a')
			write (1, "sa\n", 3);
		else if (c == 'b')
			write (1, "sb\n", 3);
	}
}

void	swap_s(t_stack **A, t_stack **B)
{
	swap_element (A, '0');
	swap_element (B, '0');
	write (1, "ss\n", 3);
}

void	push_element(t_stack **A, t_stack **B, char c)
{
	t_stack	*temp;
	t_stack	**tmp_stack;
	t_stack	**push_to;

	if (c == 'a')
	{
		push_to = A;
		tmp_stack = B;
		write (1, "pa\n", 3);
	}
	else
	{
		push_to = B;
		tmp_stack = A;
		write (1, "pb\n", 3);
	}
	if (*tmp_stack)
	{
		temp = pop_elm (tmp_stack);
		push_elm (push_to, temp);
	}
}

void	rotate_stack(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*top;

	temp = NULL;
	if (*stack != NULL)
	{
		top = pop_elm (stack);
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = top;
		temp->next->next = NULL;
		if (c == 'a')
			write (1, "ra\n", 3);
		else if (c == 'b')
			write (1, "rb\n", 3);
	}
}
