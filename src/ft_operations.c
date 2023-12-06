/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:58:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 18:58:47 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	start_with_merge(t_stack **stk_a, t_stack **stk_b)
{
	int		size;
	int		index;
	t_stack	*current;

	size = (ft_stacksize(*stk_a) / 2);
	index = 0;
	while (index < size)
	{
		index++;
		current = *stk_a;
		if (current->stay)
			ft_rotate(stk_a, 'a');
		ft_push(stk_b, stk_a, 'b');
	}
}
int	search_perfect(t_stack *stk_a, t_stack *stk_b, t_ps *sp)
{
	sp->index = 1;
	sp->cur_a = stk_a;
	while (sp->cur_a)
	{
		sp->cur_b = stk_b;
		while (sp->cur_b)
		{
			if (sp->cur_a->value == sp->cur_b->n_neighbour)
				return (sp->index);
			else if (sp->cur_a->value == sp->cur_b->p_neighbour)
				return (sp->index);
			else
				sp->index++;
			sp->cur_b = sp->cur_b->next;
		}
		sp->cur_a = sp->cur_a->next;
	}
	return (-1);
}

void	move_perfect_head(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;

	cur_a = *stk_a;
	cur_b = *stk_b;
	if (cur_a->value == cur_b->p_neighbour)
	{
		ft_push(stk_a, stk_b, 'a');
		ft_rev_rotate(stk_a, 'a');
	}
	else if (cur_a->value == cur_b->n_neighbour)
	{
		ft_push(stk_a, stk_b, 'a');
		ft_swap(stk_a, 'a');
		ft_rev_rotate(stk_a, 'a');
	}
	else
	{
		ft_printf("\nvalue = %d\nNext = %d Prev = %d\n", cur_a->value,
				cur_a->n_neighbour, cur_a->p_neighbour);
		// ft_rev_rotate_ab(stk_a, stk_b);
	}
}
// void	move_perfect_stack(t_stack **stk_a, t_stack **stk_b)
// {
// 	t_stack *current;
// 	t_stack *tmp;

// 	current = *stk_a;
// 	tmp = *stk_b;
// 	if (current->value == tmp->p_neighbour)
// 	{
// 		ft_push(stk_a, stk_b, 'a');
// 		ft_rev_rotate(stk_a, 'a');
// 	}
// 	else if (current->value == tmp->n_neighbour)
// 	{
// 		ft_push(stk_a, stk_b, 'a');
// 		ft_swap(stk_a, 'a');
// 		ft_rev_rotate(stk_a, 'a');
// 	}
// 	else
// 	{
// 		ft_printf("\nvalue = %d\nNext = %d Prev = %d\n", current->value,
// 				current->n_neighbour, current->p_neighbour);
// 		// ft_rev_rotate_ab(stk_a, stk_b);
// 	}
// }

// incomplete