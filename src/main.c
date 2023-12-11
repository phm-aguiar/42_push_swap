/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:24:35 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:19:21 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	root;

	if (argc == 1)
		exit(EXIT_FAILURE);
	configure_system(&root, argc, argv);
	initialize_data_structures(&root);
	teste_sort_next(&root.stack_a);
	ft_printf("a: \n");
	print_stack(&root, 'a');
	ft_printf("b: \n");
	print_stack(&root, 'b');
	root.status.last(&root);
}
// print_tab(&root);
