/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:10:06 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/13 16:52:18 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// functions parsing
int	len(char *av)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (av[i])
	{
		if ((av[i] > 13 || av[i] < 9) && av[i] != 32 && av[i])
			l++;
		while ((av[i] > 13 || av[i] < 9) && av[i] != 32 && av[i])
		{
			i++;
			l++;
		}
		if (av[i])
			i++;
	}
	return (l);
}

char	*skip_spaces(char *av)
{
	int		i;
	int		l;
	int		k;
	char	*j;

	i = 0;
	k = 0;
	j = malloc(sizeof(char ) * len(av) + 1);
	if (!j)
		return (NULL);
	while (av[i])
	{
		l = 0;
		while ((av[i] > 13 || av[i] < 9) && av[i] != 32 && av[i])
		{
			j[k++] = av[i++];
			l = 1;
		}
		if (l == 1)
			j[k++] = ' ';
		if (av[i])
			i++;
	}
	j[k] = '\0';
	return (j);
}

// function push_swap

t_list	*set_stack(int *arr, t_list *lst, char **av)
{
	t_list	*a;
	int		i;
	int		k;

	i = 0;
	k = check_spaces(0, 0, 0, av);
	lst = ft_lstnew(arr[i]);
	i++;
	while (i < k)
	{
		a = ft_lstnew(arr[i]);
		ft_lstadd_back(&lst, a);
		i++;
	}
	return (lst);
}

void	check_sort(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_lstsize(lst);
	tmp = lst;
	while (i < j - 1)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return ;
		i++;
	}
	exit (0);
}

void	ra(t_list **stack_a, int i)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		if (i == 0)
			write (1, "ra\n", 3);
	}
}
