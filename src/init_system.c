/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:35:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:20:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	configure_system(t_ps *scs, int argc, char **argv)
{
	scs->size = --argc;
	scs->unsorted_values = ++argv;
	scs->stack_a = NULL;
	scs->stack_b = NULL;
	scs->sorted_array = (int *)malloc(sizeof(int) * scs->size);
	if (!scs->sorted_array)
		exit(EXIT_FAILURE);
	scs->status.first = initial_errors;
	scs->status.mid = ft_error;
	scs->status.last = ft_success;
}

void	configure_node_index(t_ps *scni)
{
	t_stack	*current;
	int		j;

	current = scni->stack_a;
	while (current)
	{
		j = 0;
		while (j < scni->size)
		{
			if (current->value == scni->sorted_array[j])
			{
				current->index = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
}

void	configure_node_neighbors(t_ps *scnne)
{
	t_stack	*current;

	current = scnne->stack_a;
	while (current)
	{
		if (current->index != 0 && current->index != scnne->size - 1)
			current->next_n = current->index + 1;
		else if (current->index == 0)
			current->next_n = current->index + 1;
		else if (current->index == scnne->size - 1)
			current->next_n = 0;
		current = current->next;
	}
}
