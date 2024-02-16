/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:21:53 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 10:44:31 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort_bonus(t_list *lst)
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
		{
			write (1, "KO\n", 3);
			return ;
		}
		i++;
	}
	write (1, "OK\n", 3);
}

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_move1(char *move, t_list **stack_a, t_list **stack_b)
{
	if (move[0] == 'r')
	{
		if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
			ra(stack_a, 1);
		else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
			rb(stack_b, 1);
		else if (move[1] == 'r' && move[2] == '\n' && move[3] == '\0')
			rr(stack_a, stack_b, 1);
		else if (move[1] == 'r' && move[2] == 'a' && move[3] == '\n'
			&& move[4] == '\0')
			rra(stack_a, 1);
		else if (move[1] == 'r' && move[2] == 'b' && move[3] == '\n'
			&& move[4] == '\0')
			rrb(stack_b, 1);
		else if (move[1] == 'r' && move[2] == 'r' && move[3] == '\n'
			&& move[4] == '\0')
			rrr(stack_a, stack_b, 1);
		else
			ft_error();
	}
	else
		ft_error();
}

static void	ft_move(char *move, t_list **stack_a, t_list **stack_b)
{
	if (move[0] == 's')
	{
		if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
			sa(stack_a, 1);
		else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
			sb(stack_b, 1);
		else if (move[1] == 's' && move[2] == '\n' && move[3] == '\0')
			ss(stack_a, stack_b, 1);
		else
			ft_error();
	}
	else if (move[0] == 'p')
	{
		if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
			pa(stack_a, stack_b, 1);
		else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
			pb(stack_a, stack_b, 1);
		else
			ft_error();
	}
	else
		ft_move1 (move, stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*move;
	int		*arr;

	stack_a = NULL;
	arr = parsing(ac, av);
	if (!arr)
		return (0);
	stack_a = set_stack(arr, stack_a, av);
	free(arr);
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		ft_move (move, &stack_a, &stack_b);
		free (move);
	}
	if (stack_b)
		return (write (1, "KO\n", 3), exit(0), 0);
	check_sort_bonus(stack_a);
	free_node(&stack_a);
}
