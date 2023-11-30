/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:00:49 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 15:29:47 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_stack **a)
{
	int		temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	ft_printf("\nSwap A\n");
}


/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

void	ft_swap_b(t_stack **b)
{
	int		temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	ft_printf("\nSwap B\n");
}

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */


void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	ft_printf("\nSwap SS\n");
}
/* ss: sa and sb at the same time. */