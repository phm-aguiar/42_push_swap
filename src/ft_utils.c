/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:48:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 18:41:37 by phenriq2         ###   ########.fr       */
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
// void	set_min(t_stack **stack)
// {
// 	t_stack	*current;
// 	int		min;

// 	current = *stack;
// 	min = current->value;
// 	while (current)
// 	{
// 		if (current->value < min)
// 			min = current->value;
// 		current = current->next;
// 	}
// 	current = *stack;
// 	while (current)
// 	{
// 		if (current->value == min)
// 			current->min = 1;
// 		current = current->next;
// 	}
// }

// void	set_max(t_stack **stack)
// {
// 	t_stack	*current;
// 	int		max;

// 	current = *stack;
// 	max = current->value;
// 	while (current)
// 	{
// 		if (current->value > max)
// 			max = current->value;
// 		current = current->next;
// 	}
// 	current = *stack;
// 	while (current)
// 	{
// 		if (current->value == max)
// 			current->max = 1;
// 		current = current->next;
// 	}
// }
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
int	cmp_values(int a, int b)
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

void	ft_sort_int_tab(int *a, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
			j--;
		}
		i++;
	}
}

int	*ft_sort_array(int argc, char **argv)
{
	int	*sorted;
	int	index;

	index = 0;
	sorted = (int *)malloc(sizeof(int) * argc);
	if (sorted == NULL)
		return (NULL);
	while (index < argc)
	{
		sorted[index] = ft_atoi(*argv++);
		index++;
	}
	ft_sort_int_tab(sorted, argc);
	return (sorted);
}

int	find_next(int value, int *sorted, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (value == sorted[size - 1])
			return (INT_MAX);
		if (value == sorted[index])
			return (sorted[index + 1]);
		index++;
	}
	return (INT_MAX);
}

int	find_prev(int value, int *sorted, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (value == sorted[0])
			return (INT_MIN);
		if (value == sorted[index])
			return (sorted[index - 1]);
		index++;
	}
	return (INT_MIN);
}

void	set_neighbour(t_stack **stack, int *sorted, int size)
{
	t_stack	*current;

	current = (*stack);
	while (current)
	{
		current->n_neighbour = find_next(current->value, sorted, size);
		current->p_neighbour = find_prev(current->value, sorted, size);
		current = current->next;
	}
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



