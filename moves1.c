/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:34:45 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/15 13:35:51 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_a && (*stack_a)->next != NULL)
	{
		last = ft_lstlast(*stack_a);
		tmp = (*stack_a)->next->next;
		tmp->re = *stack_a;
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->re = last;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->re = (*stack_a);
		last->next = (*stack_a);
		if (i == 0)
			write (1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack_b && (*stack_b)->next != NULL)
	{
		last = ft_lstlast(*stack_b);
		tmp = (*stack_b)->next->next;
		tmp->re = *stack_b;
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->re = last;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
		tmp->re = (*stack_b);
		last->next = (*stack_b);
		if (i == 0)
			write (1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b, int i)
{
	sa(stack_a, 1);
	sa(stack_b, 1);
	if (i == 0)
		write (1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*lst;
	t_list	*l;

	if (*stack_b)
	{
		lst = *stack_b;
		l = ft_lstlast((*stack_b));
		*stack_b = (*stack_b)->next;
		(*stack_b)->re = l;
		l->next = *stack_b;
		ft_lstadd_front(stack_a, lst);
		if ((*stack_b)->content == lst->content)
			*stack_b = NULL;
		if (i == 0)
			write (1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int i)
{
	t_list	*lst;
	t_list	*l;

	if (*stack_a)
	{
		lst = *stack_a;
		l = ft_lstlast((*stack_a));
		*stack_a = (*stack_a)->next;
		(*stack_a)->re = l;
		l->next = *stack_a;
		ft_lstadd_front(stack_b, lst);
		if ((*stack_a)->content == lst->content)
			*stack_a = NULL;
		if (i == 0)
			write (1, "pb\n", 3);
		if (ft_lstsize(*stack_b) == 1)
			free(lst);
	}
}
