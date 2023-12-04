/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:54:29 by phenriq2          #+#    #+#             */
/*   Updated: 2023/12/04 12:29:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	floadf(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j] && str[i] != '*')
			{
				str[j] = '*';
			}
			j++;
		}
		i++;
	}
}

void	ft_union(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j] && str1[i] != '*')
			{
				str2[j] = '*';
				break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;

	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		floadf(str1);
		floadf(str2);
		ft_union(str1, str2);
		while (*str1)
		{
			if (*str1 != '*')
				write(1, str1, 1);
			str1++;
		}
		while (*str2)
		{
			if (*str2 != '*')
				write(1, str2, 1);
			str2++;
		}
	}
}
