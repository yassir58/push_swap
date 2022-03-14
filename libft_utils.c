/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:32:33 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 14:50:10 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			||str[i] == '\f' || str[i] == '\r') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

char	*ft_strdup(const char *s1)
{
	char	*res ;
	int		len ;
	int		i;

	i = 0;
	len = 0;
	while (s1[len] != 0)
		len++;
	res = malloc((len * sizeof(char)) + 1);
	if (res != 0)
	{
		while (s1[i] != 0)
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = 0;
		return (res);
	}
	return (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else if (s1[i] < s2[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

void	sort_helper_1(t_stack **a_top)
{
	swap_element (a_top, 'a');
	rotate_stack (a_top, 'a');
}

void	sort_helper_2(t_stack **a_top)
{
	swap_element (a_top, 'a');
	r_rotate_stack (a_top, 'a');
}
