/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbabken <anbabken@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:13:07 by anbabken          #+#    #+#             */
/*   Updated: 2023/07/06 19:24:20 by anbabken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b) 
{
	int	t = *a;

	*a = *b;
	*b = t;
}

int	partition(int *array, int i, int j) {

	int	pivot;
	int	low_index;
	int	high_index;
	int	k;
	
	pivot = i;
	low_index = i;
	high_index = i;
	k = i + 1;
	
	while(k < j)
	{
		if(array[k] > array[pivot])
			high_index++;
		if(array[k] < array[pivot])
		{
			low_index++;
			ft_swap(&array[low_index], &array[k]);
			high_index++;
		}
		k++;
	}
	ft_swap(&array[pivot], &array[low_index]);
	pivot = low_index;
	return (low_index);
}

void	quick_sort_rec(int *array, int i, int j)
{
	int	pivot;
	if(i == j)
		return ;
	pivot = partition(array, i, j);
	quick_sort_rec(array, i, pivot);
	quick_sort_rec(array, pivot + 1, j);
}

void	quick_sort(int *arr, int size_arr)
{
	quick_sort_rec(arr, 0, size_arr);
}


// void	printArray(int array[], int size) {
//   for (int i = 0; i < size; ++i) {
//     printf("%d  ", array[i]);
//   }
//   printf("\n");
// }

// int	main() {
//   int data[] = {8, 7, 2, 1, 0, 9, 6};
  
//   int n = sizeof(data) / sizeof(data[0]);
  
//   printf("Unsorted Array\n");
//   printArray(data, n);
  
//   quick_sort(data, n - 1);
  
//   printf("Sorted array in ascending order: \n");
//   printArray(data, n);
// }