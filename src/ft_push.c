/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:46:10 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/03 17:03:59 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
}

/* pa (push a): Take the first element at 
the top of b and put it at the top of a.
Do nothing if b is empty. */

/* pb (push b): Take the first element at the top 
of a and put it at the top of b.
Do nothing if a is empty. */