/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:06:44 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/01/17 15:43:56 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*d;

	if (!lst)
		return (0);
	d = lst;
	while (d->next != lst)
	{
		d = d->next;
	}
	return (d);
}
// int main ()
// {
// 	t_list *a = ft_lstnew(1);
// 	t_list *b = ft_lstnew(2);
// 	t_list *c = ft_lstnew(3);
// 	a->next = b;
// 	b->next = c;
// 	c->next = a;
// 	printf ("%d",ft_lstlast(a)->content);
// }