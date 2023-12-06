/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:09:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/06 18:49:17 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_values(t_ps *iv)
{
	iv->xy.x = 0;
	iv->xy.y = 0;
	iv->op = 0;
	iv->index = 0;
	iv->cur_a = NULL;
	iv->cur_b = NULL;
	iv->size_a = 0;
	iv->size_b = 0;
	iv->del = free;
}