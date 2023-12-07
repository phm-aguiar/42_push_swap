/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:59:24 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 23:01:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	cmp_values(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

int	moviment_count(t_stack **stack_a, t_stack **stack_b, t_ps *mc)
{
	int	count;
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(*stack_a);
	len_b = ft_stacksize(*stack_b);
	count = search_perfect(*stack_a, *stack_b, mc);
	if (count % len_a == 0)
		count = count / len_a * -1;
	else if (count % len_b == 0)
		count = count / len_b * -1;
	else
	{
		if (count > len_a && mc->op == 'a')
			count /= len_b * -1;
		else if (count > len_b && mc->op == 'b')
			count /= len_a * -1;
	}
	return (count);
}
