/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:00:49 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/03 15:29:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **a, char c)
{
	int		temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}


/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */


void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap(a, 'x');
	ft_swap(b, 'x');
	ft_printf("SS\n");
}
/* ss: sa and sb at the same time. */