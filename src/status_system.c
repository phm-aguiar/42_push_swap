/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_system.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:37:06 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 12:23:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clean_lst(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*current;

	current = lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	initial_errors(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error(t_ps *sfe)
{
	ft_putstr_fd("Error\n", 2);
	if (sfe->stack_a)
		clean_lst(sfe->stack_a);
	if (sfe->sorted_array)
		free(sfe->sorted_array);
	exit(EXIT_FAILURE);
}

void	ft_success(t_ps *sfs)
{
	if (sfs->stack_a)
		clean_lst(sfs->stack_a);
	if (sfs->sorted_array)
		free(sfs->sorted_array);
	exit(EXIT_SUCCESS);
}
