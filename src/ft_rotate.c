/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:59:03 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 19:05:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_last(*stack_a)->next = temp_node;
		temp_node->next = NULL;
	}
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*temp_node;

	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = NULL;
		ft_last(*stack_b)->next = temp_node;
	}
	ft_printf("rb\n");
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;

	if (*stack_a && (*stack_a)->next)
	{
		temp_node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_last(*stack_a)->next = temp_node;
		temp_node->next = NULL;
	}
	if (*stack_b && (*stack_b)->next)
	{
		temp_node = *stack_b;
		*stack_b = (*stack_b)->next;
		temp_node->next = NULL;
		ft_last(*stack_b)->next = temp_node;
	}
	ft_printf("rr\n");
}
