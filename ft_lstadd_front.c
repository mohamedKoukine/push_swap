/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:32:15 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/10 08:36:36 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = ft_lstnew(new->content);
		return ;
	}
	new->next = *lst;
	new->re = ft_lstlast((*lst));
	ft_lstlast((*lst))->next = new;
	(*lst)->re = new;
	*lst = new;
}
