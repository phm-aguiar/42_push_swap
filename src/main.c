/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:17:07 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 10:53:53 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_print_stack(t_stack *stack)
// {
// 	t_stack	*current;

// 	current = stack;
// 	while (current)
// 	{
// 		ft_printf("value: %d helf: %d high: %d low: %d\n", current->value,
// 				current->index, current->high, current->low);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = create_stack(argc - 1, ++argv);
	check_duplicate(stack_a);
	stack_b = NULL;
	find_high(&stack_a);
	find_low(&stack_a);
	while (stack_a)
		min_to_b(&stack_a, &stack_b);
	while (stack_b)
		ft_push(&stack_a, &stack_b, 'b');
	clear_stack(&stack_a, free, "Finish test.");
	return (0);
}
