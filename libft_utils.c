#include "push_swap.h"

/*
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
}*/

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