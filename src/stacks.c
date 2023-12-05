/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:52:45 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/05 18:48:15 by phenriq2         ###   ########.fr       */
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
			clear_stack(&stack, free, 42);
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			clear_stack(&stack, free, 42);
		tmp->value = ft_atoi(*argv++);
		tmp->next = NULL;
		end_add(&stack, tmp);
		index++;
	}
	return (stack);
}
