/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:57:57 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 11:36:37 by zeenyt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

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
	ft_printf("\n\n%s\n\n", msg);
	if (!ft_strcmp(msg, "Finish test."))
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
