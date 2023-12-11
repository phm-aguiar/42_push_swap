/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_tratament_system.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:42:06 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 19:06:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	configue_id(t_stack *stack)
{
	t_stack	*current;
	int		weight;
	int		midle;

	current = stack;
	weight = 0;
	midle = (ft_stacksize(current) + 1) / 2;
	while (current)
	{
		if (weight < midle)
			current->stack_id = weight;
		else
			current->stack_id = ft_stacksize(stack) - weight;
		weight++;
		current = current->next;
	}
}

void	divide_half(t_ps *sdh)
{
	t_stack	*current;
	int		index;
	int		size;

	index = 0;
	current = sdh->stack_a;
	size = (ft_stacksize(current) / 2);
	while (index < size)
	{
		current = sdh->stack_a;
		if (current->index % 2 == 0)
		{
			rotate_a(&sdh->stack_a);
			continue ;
		}
		push_b(&sdh->stack_a, &sdh->stack_b);
		index++;
	}
}

void	initialize_data_structures(t_ps *sids)
{
	t_stack	*temp;

	temp = create_stack(sids);
	if (temp == NULL)
		ft_error(sids);
	sids->stack_a = temp;
	initialize_and_sort(sids);
	configure_node_index(sids);
	configure_node_neighbors(sids);
	configue_id(sids->stack_a);
	divide_half(sids);
}
