/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:53:38 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/06 23:30:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	check_duplicate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				clear_stack(&stack, free, 42);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// void	is_max_or_min(char **argv)
// {
// 	const char	*current;
// 	long		max;
// 	long		min;
// 	int			i;

// 	i = 0;
// 	max = INT_MAX;
// 	min = INT_MIN;
// 	current = *argv;
// 	while (current[i])
// 	{
// 		if (ft_atoi(current) >= max || ft_atoi(current) <= min)
// 			exit(EXIT_FAILURE);
// 		current++;
// 	}
// }
