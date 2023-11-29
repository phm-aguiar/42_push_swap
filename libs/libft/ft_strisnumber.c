/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeenyt <zeenyt@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:19:47 by zeenyt            #+#    #+#             */
/*   Updated: 2023/11/29 11:22:29 by zeenyt           ###   ########.fr       */
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
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}