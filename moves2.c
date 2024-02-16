/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:13:26 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/13 17:02:20 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **stack_b, int i)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		if (i == 0)
			write (1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int i)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (i == 0)
		write (1, "rr\n", 3);
}

void	rra(t_list **stack_a, int i)
{
	t_list	*lst;

	if ((*stack_a) && (*stack_a)->next)
	{
		lst = ft_lstlast(*stack_a);
		*stack_a = lst;
		if (i == 0)
			write (1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int i)
{
	t_list	*lst;

	if ((*stack_b) && (*stack_b)->next)
	{
		lst = ft_lstlast(*stack_b);
		*stack_b = lst;
		if (i == 0)
			write (1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, int i)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (i == 0)
		write (1, "rrr\n", 4);
}
