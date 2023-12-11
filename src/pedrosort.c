/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pedrosort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:24:13 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:46:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c && a > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
}

t_xy	find_perfect_next(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*aux;
	t_xy	xy;
	int		size;

	xy.x = 0;
	temp = *stack_a;
	aux = (*stack_a)->next;
	size = ft_stacksize(temp);
	while (xy.x < size)
	{
		xy.y = 1;
		while (aux)
		{
			if (temp->index + 2 == aux->index)
				return (xy);
			xy.y++;
			aux = aux->next;
		}
		xy.x++;
		temp = temp->next;
	}
	return (xy);
}

void	teste_sort_next(t_stack **stack_a)
{
	t_xy	xy;
	int		middle;

	middle = (ft_stacksize(*stack_a) + 1) / 2;
	xy = find_perfect_next(stack_a);
	if (is_lst_sorted(*stack_a))
		return ;
	ft_printf("x: %d y: %d\n", xy.x, xy.y);
	if (xy.x == 0 && xy.y == 1)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (xy.y > 1 && middle >= xy.y)
	{
		while (xy.y-- > 0)
			rotate_a(stack_a);
		teste_sort_next(stack_a);
	}
	else if (xy.y > 1 && middle < xy.y)
	{
		while (xy.y-- > 0)
			reverse_rotate_a(stack_a);
		teste_sort_next(stack_a);
	}
}
