/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:39 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/12 15:31:00 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	word_count;
	int	state;
	int	i;

	state = 0;
	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i++] = NULL;
	}
	free(tab);
}

static char	*fill_tab(char const *s, int *start, int finish, char **tab)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((finish - *start + 1) * sizeof(char));
	if (!str)
		free_tab(tab);
	while ((*start) < finish)
		str[i++] = s[(*start)++];
	str[i] = '\0';
	*start = -1;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
			tab[j++] = fill_tab(s, &index, i, tab);
		i++;
	}
	tab[j] = 0;
	return (tab);
}
