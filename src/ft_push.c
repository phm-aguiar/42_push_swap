/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:52 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 19:04:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* pa (push a): Take the first element at
the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top
of a and put it at the top of b.
Do nothing if a is empty. */

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp_node = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_node->next = *stack_a;
	*stack_a = temp_node;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	temp_node = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_node->next = *stack_b;
	*stack_b = temp_node;
	ft_printf("pb\n");
}
