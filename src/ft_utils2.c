/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:47:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 23:18:34 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_int_tab(int *a, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
		i++;
	}
}

int	*ft_sort_array(int argc, char **argv)
{
	int	*sorted;
	int	index;

	index = 0;
	sorted = (int *)malloc(sizeof(int) * argc);
	if (sorted == NULL)
		return (NULL);
	while (index < argc)
	{
		sorted[index] = ft_atoi(*argv++);
		index++;
	}
	ft_sort_int_tab(sorted, argc);
	return (sorted);
}

int	find_next(int value, int *sorted, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (value == sorted[size - 1])
			return (INT_MAX);
		if (value == sorted[index])
			return (sorted[index + 1]);
		index++;
	}
	return (INT_MAX);
}

int	find_prev(int value, int *sorted, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (value == sorted[0])
			return (INT_MIN);
		if (value == sorted[index])
			return (sorted[index - 1]);
		index++;
	}
	return (INT_MIN);
}
