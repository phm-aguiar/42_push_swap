/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:59:09 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 19:00:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. 
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void	ft_swap(t_stack **a, char c)
{
	int	temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
}

/* ss: sa and sb at the same time. */
void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap(a, 'x');
	ft_swap(b, 'x');
	ft_printf("ss\n");
}
