/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:41 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/03 17:03:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*current;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	current = (*stack)->next;
	(*stack) = current;
	first->next = NULL;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rotate(a, ' ');
	ft_rotate(b, ' ');
	ft_printf("rr\n");
}

void	ft_rev_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*current;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	current = (*stack);
	while (current->next != NULL)
		current = current->next;
	last = current;
	current = (*stack);
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_rev_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a, ' ');
	ft_rev_rotate(b, ' ');
	ft_printf("rrr\n");
}
