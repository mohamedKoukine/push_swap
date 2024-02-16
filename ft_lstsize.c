/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:44:42 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/01/30 12:57:25 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*d;

	d = lst;
	if (d)
	{
		d = d -> next;
		i = 1;
	}
	while (d != lst)
	{
		d = d -> next;
		i++;
	}
	return (i);
}
