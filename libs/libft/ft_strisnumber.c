/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:19:47 by zeenyt            #+#    #+#             */
/*   Updated: 2023/12/03 13:07:10 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumber(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index])
	{
		if (str[index] == ' ' || str[index] == '\t')
		{
			index++;
			continue ;
		}
		if (ft_isdigit(str[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
