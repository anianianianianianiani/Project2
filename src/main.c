/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:53:14 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/03 20:17:30 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **av)
{
	char	**test;
	valid_check(av);
	if (argc > 1)
	{
		test = join_args(argc, av);
		if (*test == NULL)
			return (0);
		if (arg_check(test) != 0)
			free_dp(&test, 1);
	}
	return (0);
}
