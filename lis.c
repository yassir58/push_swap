/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:27:16 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 13:33:11 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_elm(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	free_stack(t_stack **stack)
{
	t_stack	*elm;
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		elm = pop_elm (stack);
		free (elm);
		temp = *stack;
	}
}

int	check_if_sorted(t_stack *stack)
{
	int		checker;
	t_stack	*temp;

	checker = 0;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->data < checker)
			return (0);
		checker = temp->data;
		temp = temp->next;
	}
	return (1);
}

void	set_indx_len(t_stack **node, int len, int indx)
{
	t_stack	*tmp;

	tmp = *node;
	tmp->len = len;
	tmp->indx = indx;
}

void	free_all(t_stack *A, t_stack *B)
{
	free_stack (&A);
	free_stack (&B);
	free (A);
	free (B);
}
