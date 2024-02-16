/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my3_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:20:50 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/13 17:03:52 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	*place_in_push(t_list **stack_a, t_list **stack_b, int i, int j)
{
	t_list	*lst;
	t_list	*lst1;

	lst = *stack_a;
	lst1 = *stack_a;
	while (++i < j)
	{
		if (lst1->content > (*stack_b)->content)
		{
			i = -1;
			while (++i < j)
			{
				if (lst->content < lst1->content
					&& (*stack_b)->content < lst->content)
					lst1 = lst;
				lst = lst->next;
			}
			break ;
		}
		lst1 = lst1->next;
	}
	return (lst1);
}

static void	fill_move(t_list *stack_a, t_list *stack_b, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (stack_a->index <= (size / 2) + 1)
			stack_a->tmp = stack_a->index - 1;
		else
			stack_a->tmp = size - stack_a->index + 1;
		stack_a = stack_a->next;
	}
	if (stack_b)
	{
		size = ft_lstsize(stack_b);
		i = -1;
		while (++i < size)
		{
			if (stack_b->index <= (size / 2) + 1)
				stack_b->tmp = stack_b->index;
			else
				stack_b->tmp = size - stack_b->index + 2;
			stack_b = stack_b->next;
		}
	}
}

void	best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;
	int		size;
	int		i;

	i = 0;
	lst = NULL;
	fill_index(*stack_b);
	fill_index(*stack_a);
	fill_move(*stack_a, *stack_b, ft_lstsize(*stack_a));
	size = ft_lstsize(*stack_b);
	while (i < size)
	{
		(*stack_b)->tmp += place_in_push(stack_a, stack_b, -1,
				ft_lstsize(*stack_a))->tmp;
		*stack_b = (*stack_b)->next;
		i++;
	}
}

static void	push_to_stack_a1(t_list	*lst, t_list *min_tmp
	, t_list **stack_a, t_list **stack_b)
{
	if (min_tmp->index <= (ft_lstsize((*stack_b)) / 2) + 1)
	{
		while (min_tmp != *stack_b)
			rb(stack_b, 0);
	}
	else
	{
		while (min_tmp != *stack_b)
			rrb(stack_b, 0);
	}
	lst = place_in_push(stack_a, stack_b, -1, ft_lstsize(*stack_a));
	if (lst->index <= (ft_lstsize((*stack_a)) / 2) + 1)
	{
		while (lst != *stack_a)
			ra(stack_a, 0);
	}
	else
	{
		while (lst != *stack_a)
			rra(stack_a, 0);
	}
}

void	push_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*lst;
	t_list	*min_tmp;
	int		i;

	i = 0;
	best_move(stack_a, stack_b);
	lst = (*stack_b)->next;
	min_tmp = (*stack_b);
	while (i < ft_lstsize(*stack_b))
	{
		if (lst->tmp < min_tmp->tmp)
			min_tmp = lst;
		lst = lst->next;
		i++;
	}
	lst = place_in_push(stack_a, &min_tmp, -1, ft_lstsize(*stack_a));
	if (min_tmp == ft_lstlast((*stack_b)) && lst == ft_lstlast((*stack_a)))
		rrr(stack_a, stack_b, 0);
	else
		push_to_stack_a1(lst, min_tmp, stack_a, stack_b);
	pa(stack_a, stack_b, 0);
	fill_index(*stack_a);
	fill_index(*stack_b);
}
