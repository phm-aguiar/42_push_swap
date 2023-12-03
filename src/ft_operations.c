/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:50 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/03 18:25:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_stack **a)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = *a;
	while (current)
	{
		current->index = index++;
		current = current->next;
	}
}

void	min_to_b(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		len;
	int		index;

	index = 0;
	assign_index(a);
	find_low(a);
	current = *a;
	len = (ft_stacksize(*a) - 1) / 2;
	current = *a;
	while (current->low != 1)
	{
		ft_rotate(a, 'a');
		current = *a;
	}
	ft_push(b, a, 'a');
}
