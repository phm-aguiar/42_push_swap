/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:17:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 19:02:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current)
		ft_printf("Stack b is empty.\n");
	while (current)
	{
		ft_printf("value: %d\n", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stack(argc - 1, ++argv);
	check_duplicate(stack_a);
	stack_b = NULL;
	ft_quick_sort(&stack_a);
	// ft_print_stack(stack_a);
	clear_stack(&stack_a, free, "Finish test.");
	return (0);
}
