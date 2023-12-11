/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_list_system.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:42:19 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:45:36 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	is_lst_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_stack	*ft_last(t_stack *lst)
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
	last = ft_last(*lst);
	last->next = new_node;
}

t_stack	*create_stack(t_ps *scs)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		index;

	index = 0;
	stack = NULL;
	while (index < scs->size)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			ft_error(scs);
		tmp->index = 0;
		tmp->next_n = 0;
		tmp->stack_id = 0;
		tmp->value = ft_atol(scs->unsorted_values[index]);
		tmp->next = NULL;
		end_add(&stack, tmp);
		index++;
	}
	return (stack);
}
