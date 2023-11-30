/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:17:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:37 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*current;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stack(argc - 1, ++argv);
	check_duplicate(stack_a);
	stack_b = NULL;
	current = stack_a;
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_swap_a(&stack_a);
	ft_push_b(&stack_a, &stack_b);
	ft_push_b(&stack_a, &stack_b);
	ft_swap_b(&stack_b);
	current = stack_b;
	ft_swap_a(&stack_a);
	ft_printf("\n B:");
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	current = stack_a;
	ft_printf("\n A:");
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	clear_stack(&stack_a, free, "Finish test.");
	return (0);
}
