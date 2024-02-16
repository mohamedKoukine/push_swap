/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my2_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:26:00 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 10:58:08 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	true_false(t_list *stack)
{
	t_list	*lst;
	t_list	*lst_next;

	lst_next = stack->next;
	lst = stack;
	while (lst != lst_next)
	{
		if (stack->tmp < lst_next->tmp)
			stack = lst_next;
		lst_next = lst_next->next;
	}
	lst_next = stack->next;
	stack->tandf = false;
	lst = stack;
	while (stack->content != lst_next->content)
	{
		if (lst->content < lst_next->content)
		{
			lst_next->tandf = false;
			lst = lst_next;
		}
		lst_next = lst_next->next;
	}
	return (stack->tmp);
}

int	fill_tmp(t_list *stack, int j, int i, int l)
{
	t_list	*lst;
	t_list	*lst_next;

	lst = stack;
	lst_next = stack->next;
	while (++i < j)
	{
		l = 1;
		while (stack->content != lst_next->content)
		{
			if (lst->content < lst_next->content)
			{
				l++;
				lst = lst_next;
			}
			lst_next = lst_next->next;
		}
		stack->tmp = l;
		stack->tandf = true;
		stack = stack->next;
		lst = stack;
		lst_next = stack ->next;
	}
	return (true_false(stack));
}

void	fake_swap(t_list **stack_a, t_list	**stack_b, int moyen, int largest)
{
	int	lst;

	while (ft_lstsize(*stack_a) != largest)
	{
		sa(stack_a, 1);
		lst = fill_tmp(*stack_a, ft_lstsize(*stack_a), -1, 1);
		if (lst > largest)
		{
			largest = lst;
			write (1, "sa\n", 3);
		}
		else
		{
			sa(stack_a, 1);
			lst = fill_tmp(*stack_a, ft_lstsize(*stack_a), -1, 1);
			if ((*stack_a)->tandf == false)
				ra(stack_a, 0);
			else
			{
				pb(stack_a, stack_b, 0);
				if (ft_lstsize(*stack_b) > 1 && (*stack_b)->content > moyen)
					rb(stack_b, 0);
			}
		}
	}
}

void	fill_index(t_list *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return ;
	while (i <= ft_lstsize(stack))
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	free_node(t_list	**stack)
{
	t_list	*lst;
	t_list	*last;

	while (*stack && (*stack)->next != *stack)
	{
		last = ft_lstlast(*stack);
		lst = *stack;
		*stack = (*stack)->next;
		last->next = *stack;
		free (lst);
		lst = NULL;
	}
	if (*stack)
	{
		free (*stack);
		*stack = NULL;
	}
}
