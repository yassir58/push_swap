/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:10:25 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 12:36:09 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *top)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	temp_1 = top;
	while (temp_1 != NULL)
	{
		temp_2 = temp_1->next;
		while (temp_2 != NULL)
		{
			if (temp_2->data == temp_1->data)
				return (0);
			temp_2 = temp_2->next;
		}
		temp_2 = NULL;
		temp_1 = temp_1->next;
	}
	return (1);
}

void	create_stack(t_stack **top, char *argv[])
{
	t_stack	*a_top;
	int		len;

	a_top = NULL;
	len = vector_size (argv);
	a_top = create_node (ft_atoi(argv[--len]));
	*top = a_top;
	while (len--)
		push_elm (top, create_node (atoi(argv[len])));
}

int	stack_length(t_stack *stack)
{
	t_stack	*temp;
	int		len;

	temp = stack;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_stack	*temp;

	temp = stack;
	max = 0;
	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = malloc (sizeof (t_stack));
	node->data = data;
	node->lis = 0;
	node->indx = -1;
	node->len = 1;
	node->next = NULL;
	return (node);
}
