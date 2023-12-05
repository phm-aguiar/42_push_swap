/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:48:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/05 20:08:38 by phenriq2         ###   ########.fr       */
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
void	set_min(t_stack **stack)
{
	t_stack	*current;
	int		min;

	current = *stack;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	current = *stack;
	while (current)
	{
		if (current->value == min)
			current->min = 1;
		current = current->next;
	}
}

void	set_max(t_stack **stack)
{
	t_stack	*current;
	int		max;

	current = *stack;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	current = *stack;
	while (current)
	{
		if (current->value == max)
			current->max = 1;
		current = current->next;
	}
}
void	set_weight(t_stack **stack)
{
	t_stack	*current;
	int		weight;
	int		midle;

	current = *stack;
	weight = 0;
	midle = ft_stacksize(current) / 2;
	while (current)
	{
		if (weight < midle)
			current->weight = weight;
		else
			current->weight = ft_stacksize(*stack) - weight;
		weight++;
		current = current->next;
	}
}
void	set_index(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}
int cmp_values(int a, int b)
{
	if (a < b)
		return (1);
	return (0);
}

void	moviment_cust(int cust_a, int cust_b)
{
	int	total_cust;

	total_cust = cust_a + cust_b;
}
