/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:07:31 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/04 19:22:15 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *a, int *arr, int size)
{
	int		i;
	int		j;
	t_list	*cursor;

	i = 0;
	cursor = a;
	while (i < size)
	{
		j = 0;
		while (cursor->n != arr[j])
		{
			j++;
		}
		cursor->index = j;
		cursor = cursor->next;
		i++;
	}
}

// void	push_swap(t_stack *stack)
// {
// 	int	size;

// 	get_indexs(stack->a);
// 	size = ft_lstsize(stack->a);
// 	if (sorted(stack->a) == 0)
// 		return ;
// 	if (size == 1)
// 		return ;
// 	else if (size == 2)
// 		sort2(stack);
// 	else if (size == 3)
// 		sort3(stack);
// 	else if (size <= 5)
// 		sort5(stack);
// 	else if (size > 5)
// 		push_to_b(stack);
// 	return ;
// }