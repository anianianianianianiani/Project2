/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:53:14 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/01 19:18:11 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**test;

	if (argc > 1)
	{
		test = join_args(argc, argv);
		if (*test == NULL)
			return (0);
		if (arg_check(test) != 0)
			free_dp(&test, 1);
	}
	return (0);
}
