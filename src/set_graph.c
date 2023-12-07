/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:56:16 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 23:01:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_neighbour(t_stack **stack, int *sorted, int size)
{
	t_stack	*current;

	current = (*stack);
	while (current)
	{
		current->n_neighbour = find_next(current->value, sorted, size);
		current->p_neighbour = find_prev(current->value, sorted, size);
		current = current->next;
	}
}

void	set_weight(t_stack **stack)
{
	t_stack	*current;
	int		weight;
	int		midle;

	current = *stack;
	weight = 0;
	midle = ft_stacksize(current) / 2;
	while (current)
	{
		if (weight < midle)
			current->weight = weight;
		else
			current->weight = ft_stacksize(*stack) - weight;
		weight++;
		current = current->next;
	}
}

void	set_index(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
