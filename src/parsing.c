/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:52:40 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/03 20:16:38 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation(char **res)
{
	int	n;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (res[i] != NULL)
	{
		n = ft_atoi(res[i]);
		j = i;
		while (res[++j] != NULL)
		{
			tmp = ft_atoi(res[j]);
			if (n == tmp)
			{
				i = 0;
				while (res[i])
					free(res[i++]);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}


int	fill_list(t_list **lst, int content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

int	fill_stack(t_stack *stack, char **res)
{
	int	i;
	int	n;

	i = 1;
	stack->a = ft_lstnew(ft_atoi(res[0]));
	while (res[i] != NULL)
	{
		n = ft_atoi(res[i]);
		if (res[i] == NULL)
			break ;
		fill_list(&stack->a, n);
		i++;
	}
	return (0);
}

void	valid_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i] || !*argv[i] || ft_strncmp(argv[i], " ",
				ft_strlen(argv[i])) == 0)
		{
			put_msg("Error", 2);
			exit(0);
		}
		i++;
	}
}
