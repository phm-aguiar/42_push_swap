/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:48:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 11:08:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	count;

	count = 1;
	if (!lst)
		return (0);
	while (lst->next && count++)
		lst = lst->next;
	return (count);
}

void	define_height(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!(*stack))
		return ;
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->height = i++;
		tmp = tmp->next;
	}
}
