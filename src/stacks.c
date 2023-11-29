/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:52:45 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 11:41:10 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		index;

	index = 0;
	stack = NULL;
	while (index < argc)
	{
		if (!ft_strisnumber(*argv))
			clear_stack(&stack, free, "Error: Invalid number.");
		tmp = malloc(sizeof(t_stack));
		if (tmp == NULL)
			return (NULL);
		tmp->content = ft_atoi(*argv++);
		tmp->next = stack;
		stack = tmp;
		index++;
	}
	return (stack);
}
