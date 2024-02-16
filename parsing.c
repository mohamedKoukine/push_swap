/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:09:06 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 09:28:52 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **spl, char *t)
{
	int	i;

	i = 0;
	while (spl[i])
		free(spl[i++]);
	free(spl);
	spl = NULL;
	free(t);
}

static int	*split_and_check(int i, int l, int *arr, char **av)
{
	int		k;
	int		j;
	char	**a;
	char	*t;

	while (av[++l])
	{
		t = skip_spaces(av[l]);
		a = ft_split(t, ' ');
		k = -1;
		while (a[++k])
		{
			arr[++i] = ft_atoi(a[k]);
			j = -1;
			while (++j < i)
			{
				if (arr[i] == arr[j])
					return (write (2, "Error\n", 6),
						free_all(a, t), exit (1), NULL);
			}
		}
		free_all(a, t);
	}
	return (arr);
}

int	check_spaces(int i, int j, int l, char **av)
{
	int	k;

	k = 0;
	while (av[++j])
	{
		while (av[j][i])
		{
			if (!((av[j][i] <= 13 && av[j][i] >= 9) || av[j][i] == 32))
				k++;
			else
				l++;
			while (!((av[j][i] <= 13 && av[j][i] >= 9) || av[j][i] == 32)
				&& av[j][i])
				i++;
			if (av[j][i])
				i++;
		}
		if (i == l)
			return (write (2, "Error\n", 6), 0);
		i = 0;
		l = 0;
	}
	return (k);
}

static void	check_alpha(char **av)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (av[++j])
	{
		while (av[j][++i])
		{
			if (av[j][i] <= '9' && av[j][i] >= '0' && (av[j][i + 1] == '+'
				|| av[j][i + 1] == '-'))
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			if (!((av[j][i] <= '9' && av[j][i] >= '0') || av[j][i] == '-' ||
				av[j][i] == '+' || (av[j][i] <= 13 && av[j][i] >= 9) ||
				av[j][i] == 32))
			{
				write (2, "Error\n", 6);
				exit (1);
			}
		}
		i = -1;
	}
}

int	*parsing(int ac, char **av)
{
	int	*arr;
	int	k;

	k = 0;
	arr = NULL;
	if (ac > 1)
	{
		check_alpha(av);
		k = check_spaces(0, 0, 0, av);
		if (!k)
			exit (1);
		arr = malloc(sizeof(int) * k);
		if (!arr)
			return (0);
		arr = split_and_check(-1, 0, arr, av);
	}
	return (arr);
}
