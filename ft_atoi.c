/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:00:32 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 09:28:05 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check__(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		j = -1;
	else if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		j = 1;
	else
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return (j);
}

int	ft_atoi(char *str)
{
	long	rev;
	int		i;
	int		j;

	i = 0;
	rev = 0;
	j = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		j = check__(&str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rev = rev * 10 + (str[i++] - 48);
		if (rev * j > 2147483647 || rev * j < -2147483648)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
	}
	return (rev * j);
}
