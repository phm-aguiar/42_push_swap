/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:57:57 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/05 15:46:49 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_stack(t_stack **lst, void (*del)(void *), char msg)
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
	if (msg == 42)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
