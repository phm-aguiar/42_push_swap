/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:17:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/05 20:07:26 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack, char c)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
	{
		ft_printf("Stack is empty.\n");
		return ;
	}
	ft_printf("Stack %c:\n", c);
	while (tmp)
	{
		if (tmp->value)
			ft_printf("value: %d max: %d min: %d weight: %d index %d \n",
					tmp->value, tmp->max, tmp->min, tmp->weight, tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	pre_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	start_with_merge(stack_a, stack_b);
	set_weight(stack_a);
	set_weight(stack_b);
	set_index(stack_a);
	set_index(stack_b);
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = create_stack(argc - 1, ++argv);
	check_duplicate(stack_a);
	set_min(&stack_a);
	set_max(&stack_a);
	pre_push_swap(&stack_a, &stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	// clear_stack(&stack_a, free, 42);
	return (0);
}
