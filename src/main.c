/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:59:40 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 23:26:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	ft_printf("Tab: ");
	while (i < size)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

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
			ft_printf("value:%d next:%d prev:%d weight:%d index:%d stay:%d\n",
				tmp->value, tmp->n_neighbour, tmp->p_neighbour, tmp->weight,
				tmp->index, tmp->stay);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	pre_push_swap(t_stack **stack_a, t_stack **stack_b, t_ps *pps)
{
	start_with_merge(stack_a, stack_b);
	move_perfect_head(stack_a, stack_b);
	set_weight(stack_a);
	set_weight(stack_b);
	set_index(stack_a);
	set_index(stack_b);
	ft_printf("Stack A\nvalue:%d next:%d prev:%d\n", (*stack_a)->value,
		(*stack_a)->n_neighbour, (*stack_a)->p_neighbour);
	ft_printf("Stack B\nvalue:%d next:%d prev:%d\n", (*stack_b)->value,
		(*stack_b)->n_neighbour, (*stack_b)->p_neighbour);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted;
	t_ps	root;

	init_values(&root);
	is_max_or_min(++argv);
	stack_b = NULL;
	if (argc < 2)
		return (1);
	sorted = ft_sort_array(argc - 1, argv);
	stack_a = create_stack(argc - 1, argv, sorted);
	check_duplicate(stack_a);
	set_neighbour(&stack_a, sorted, argc - 1);
	pre_push_swap(&stack_a, &stack_b, &root);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_print_tab(sorted, argc - 1);
	root.del(sorted);
	clear_stack(&stack_a, root.del, 1);
	clear_stack(&stack_b, root.del, 42);
	return (0);
}
