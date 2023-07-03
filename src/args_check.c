/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:53:11 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/03 19:37:20 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

char	**join_args(int ac, char **av)
{
	char	*str;
	char	**res;
	int		i;

	i = 2;
	str = ft_strdup(av[1]);
	while (i < ac)
	{
		str = join_str(str, " ");
		str = join_str(str, av[i]);
		i++;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

int	atoi_check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[1] == '+' || str[1] == '-' || str[1] == '\0')
			return (1);
		else
			i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

char	*limits_check(char *str)
{
	long int	res;
	int			mop;

	mop = 1;
	res = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if ((str[0] == '-') || (str[0] == '+'))
	{
		if (*str == '-')
			mop *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + ((int)*str - '0');
		if ((res > INT_MAX && mop == 1) || ((res * -1) < INT_MIN && mop == -1))
			return (ft_strdup("no"));
		str++;
	}
	return (ft_strdup("yes"));
}

int	dup_check(char **group)
{
	int	j;
	int	i;
	int	n;

	i = 0;
	while (group[i])
	{
		n = ft_atoi(group[i]);
		j = i + 1;
		while (group[j])
		{
			if (ft_atoi(group[j]) == n)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_check(char **group)
{
	int		i;
	char	*check;

	i = 0;
	while (group[i])
	{
		if (atoi_check(group[i]) == 1)
			free_dp(&group, 1);
		check = limits_check(group[i]);
		if (ft_strlen(check) == 2)
		{
			free(check);
			free_dp(&group, 1);
		}
		free(check);
		i++;
	}
	return (dup_check(group));
}
