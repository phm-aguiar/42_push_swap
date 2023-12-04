/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:57:57 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/04 10:16:28 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_stack(t_stack **lst, void (*del)(void *), char *msg)
{
	t_stack	*aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		del(*lst);
		*lst = aux;
	}
	*lst = NULL;
	if (!ft_strcmp(msg, "cleaning stack_a."))
		return ;
	if (!ft_strcmp(msg, "Finish test."))
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
