/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelatman <yelatman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:31:05 by yelatman          #+#    #+#             */
/*   Updated: 2022/03/14 13:27:28 by yelatman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_splitable(char *str)
{
	static int	i;
	static int	w_count;
	int			j;
	int			temp;

	j = 0;
	while (str[i] && str[i] != ' ')
	{
		i++;
		j++;
	}
	if (j > 0)
		w_count++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		temp = w_count;
		w_count = 0;
		i = 0;
		return (temp);
	}
	return (is_splitable (str));
}

int	vector_size(char **vector)
{
	int	size;

	size = 0;
	if (!vector)
		return (0);
	while (vector[size])
		size++;
	return (size);
}

char	**join_vector(char **dst_vector, char **src_vector)
{
	int		dst_size;
	char	**final_vector;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst_size = vector_size (dst_vector) + vector_size (src_vector) + 1;
	final_vector = (char **) malloc (sizeof (char *) * dst_size);
	if (!final_vector)
		return (NULL);
	if (dst_vector)
	{
		while (dst_vector[i])
		{
			final_vector[i] = ft_strdup (dst_vector[i]);
			i++;
		}
		free_tab (dst_vector);
	}
	while (src_vector[j])
		final_vector[i++] = ft_strdup (src_vector[j++]);
	final_vector[i] = NULL;
	free_tab (src_vector);
	return (final_vector);
}

char	**process_args(int argc, char *argv[])
{
	char	**final_vector;
	int		i;

	i = 1;
	final_vector = NULL;
	while (i < argc)
	{
		if (is_splitable(argv[i]) == 0)
			return (handle_err ());
		else if (is_splitable (argv[i]) >= 1 && !one_word (argv[i]))
			final_vector = join_vector (final_vector, ft_split (argv[i], ' '));
		else if (one_word (argv[i]))
			final_vector = join_vector (final_vector, one_word_tab(argv[i]));
		i++;
	}
	return (final_vector);
}
