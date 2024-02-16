/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:44:59 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 10:45:23 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_number(t_list **stack)
{
	t_list	*lst;
	int		tmp;

	lst = (*stack)->next;
	tmp = (*stack)->content;
	while (*stack != lst)
	{
		if (lst->content > tmp)
			tmp = lst->content;
		lst = lst->next;
	}
	return (tmp);
}

int	min_number(t_list **stack)
{
	t_list	*lst;
	int		tmp;

	lst = (*stack)->next;
	tmp = (*stack)->content;
	while (*stack != lst)
	{
		if (lst->content < tmp)
			tmp = lst->content;
		lst = lst->next;
	}
	return (tmp);
}

static void	sort_list(t_list **stack_a)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;

	i = 0;
	lst = (*stack_a)->next;
	tmp = (*stack_a);
	while (i < ft_lstsize((*stack_a)))
	{
		if (lst->content < tmp->content)
			tmp = lst;
		lst = lst->next;
		i++;
	}
	while (tmp != *stack_a)
	{
		if (tmp->index <= (ft_lstsize(*stack_a) / 2) + 1)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	arr = parsing(ac, av);
	if (arr == NULL)
		return (0);
	stack_a = set_stack(arr, stack_a, av);
	free(arr);
	check_sort(stack_a);
	fake_swap(&stack_a, &stack_b, ((max_number(&stack_a) / 2)
			+ (min_number(&stack_a) / 2)),
		fill_tmp(stack_a, ft_lstsize(stack_a), -1, 1));
	while (stack_b)
		push_to_stack_a(&stack_a, &stack_b);
	fill_index(stack_a);
	sort_list(&stack_a);
	free_node(&stack_a);
}
