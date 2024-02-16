/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:51 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/01/30 15:36:39 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*d;

	d = (t_list *)malloc(sizeof(t_list));
	if (!d)
		return (0);
	d->content = content;
	d->tmp = 1;
	d->tandf = true;
	d->next = d;
	d->re = d;
	return (d);
}
