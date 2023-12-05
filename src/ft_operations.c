/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:58:50 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/05 20:09:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_with_merge(t_stack **stk_a, t_stack **stk_b)
{
	int		size;
	int		index;
	t_stack	*current;

	current = *stk_a;
	size = ft_stacksize(current) / 2;
	index = 0;
	while (index < size)
	{
		ft_push(stk_b, stk_a, 'b');
		index++;
	}
}

void	calcule_cust(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*current;
	t_stack	*currentb;

	current = *stk_a;
	currentb = *stk_b;
	while (current->max != 1 && currentb)
	
	{
		if(cmp_values(current->value, currentb->value) && currentb){
			ft_push(stk_b, stk_a, 'b');
			ft_rotate(stk_b, 'b');
			}
		else
			{
			ft_push(stk_b, stk_a, 'a');
			ft_rotate(stk_b, 'b');
			}
			
	}
}
