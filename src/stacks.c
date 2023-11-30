/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:52:45 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 14:52:21 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_last_stack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	end_add(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_last_stack(*lst);
	last->next = new_node;
}

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
			clear_stack(&stack, free, "Error: Memory allocation failed.");
		tmp->content = ft_atoi(*argv++);
		tmp->next = NULL;
		end_add(&stack, tmp);
		index++;
	}
	return (stack);
}

t_stack	*create_stack_b(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		clear_stack(&stack, free, "Error: Memory allocation failed.");
	stack->content = value;
	stack->next = NULL;
	return (stack);
}
