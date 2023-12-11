/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:22:30 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 19:04:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*temp_node;
	t_stack	*aux;

	temp_node = ft_last(*stack_a);
	aux = *stack_a;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_a;
	(*stack_a) = temp_node;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*temp_node;
	t_stack	*aux;

	temp_node = ft_last(*stack_b);
	aux = *stack_b;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_b;
	(*stack_b) = temp_node;
	ft_printf("rrb\n");
}

void	reverse_rotate_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_node;
	t_stack	*aux;

	temp_node = ft_last(*stack_a);
	aux = *stack_a;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_a;
	(*stack_a) = temp_node;
	temp_node = ft_last(*stack_b);
	aux = *stack_b;
	while (aux->next != temp_node)
		aux = aux->next;
	aux->next = NULL;
	temp_node->next = *stack_b;
	(*stack_b) = temp_node;
	ft_printf("rrr\n");
}
