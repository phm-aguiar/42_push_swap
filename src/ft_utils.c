/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:48:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/03 16:53:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	ft_stacksize(t_stack *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next && count++)
		lst = lst->next;
	return (count);
}

void	find_high(t_stack **a)
{
	t_stack	*current;
	int		high;

	high = 0;
	current = *a;
	while (current)
	{
		if (current->content > high)
			high = current->content;
		current = current->next;
	}
	current = *a;
	while (current)
	{
		if (current->content == high)
			current->high = 1;
		current = current->next;
	}
}

void	find_low(t_stack **a)
{
	t_stack	*current;
	int		min;

	min = INT_MAX;
	current = *a;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	current = *a;
	while (current)
	{
		if (current->content == min)
			current->low = 1;
		current = current->next;
	}
}
