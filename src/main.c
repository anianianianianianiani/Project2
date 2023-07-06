/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:53:14 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:59 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*start;
	t_list	*next;

	while (stack && stack->a)
	{
		start = stack->a;
		next = stack->a;
		while (next->next)
		{
			start = next;
			next = next->next;
		}
		if (start == next)
		{
			free(stack->a);
			stack->a = NULL;
		}
		else
		{
			start->next = NULL;
			free(next);
		}
	}
	free(stack);
}

int	main(int argc, char **av)
{
	t_stack	*stack;
	char	**test;

	if (argc > 1)
	{
		valid_check(av);
		test = join_args(argc, av);
		if (*test == NULL)
			return (0);
		if (arg_check(test) != 0)
			free_dp(&test, 1);
		stack = make_stack(&test);
		quick_sort(stack, );
		
		//free_stack(stack);
	}
	return (0);
}
