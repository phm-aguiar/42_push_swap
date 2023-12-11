/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:40 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 12:18:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_array(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubble_sort(int *array, int size)
{
	int	swap;
	int	i;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap_array(&array[i], &array[i + 1]);
				swap = 1;
				i++;
			}
			i++;
		}
	}
}

void	initialize_and_sort(t_ps *sias)
{
	int	i;

	i = 0;
	if (sias->sorted_array == NULL)
		ft_error(sias);
	while (i < sias->size)
	{
		sias->sorted_array[i] = (int)ft_atol(sias->unsorted_values[i]);
		i++;
	}
	bubble_sort(sias->sorted_array, sias->size);
}
