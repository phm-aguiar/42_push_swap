/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:50 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 19:14:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_quick_sort(t_stack **a, t_stack **b)
{
	t_stack	*pivot;
	t_stack	*less;
	t_stack	*greater;

	less = NULL;
	greater = NULL;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	pivot = *a;
	*a = pivot->next;
	pivot->next = NULL;
	while (*a)
	{
		*b = *a;
		*a = (*b)->next;
		(*b)->next = NULL;
		if ((*b)->value < pivot->value)
			ft_push(&less, b, 'a');
		else
			ft_push(&greater, b, 'a');
	}
	ft_quick_sort(less);
	ft_quick_sort(&greater);
	while (less)
	{
		ft_push(a, &less, 'a');
	}
	ft_push(a, &pivot, 'a');
	while (greater)
	{
		ft_push(a, &greater, 'a');
	}
}
