/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:36:41 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 15:39:32 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pop(t_stack **head)
{
	t_stack	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	ft_rotate_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	ft_printf("\nRotate A\n");
}
