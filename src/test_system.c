/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:47:48 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/10 20:19:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_ps *sps, char c)
{
	t_stack	*tmp;

	if (c == 'a')
		tmp = sps->stack_a;
	else
		tmp = sps->stack_b;
	while (tmp)
	{
		ft_printf("value: %d, index: %d, next: %d, id: %d\n",
			tmp->value, tmp->index, tmp->next_n, tmp->stack_id);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_tab(t_ps *spt)
{
	int	i;

	i = 0;
	while (i < spt->size)
	{
		ft_printf("%d ", spt->sorted_array[i]);
		i++;
	}
	ft_printf("\n");
}
