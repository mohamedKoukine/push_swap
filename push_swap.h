/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:39:37 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/02/16 11:05:50 by mkaoukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
char	*skip_spaces(char *av);
int		len(char *av);
int		*parsing(int ac, char **av);
int		check_spaces(int i, int j, int l, char **av);

typedef struct s_list
{
	int				content;
	bool			tandf;
	int				tmp;
	int				index;
	struct s_list	*next;
	struct s_list	*re;
}			t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*set_stack(int *arr, t_list *lst, char **av);
int		fill_tmp(t_list *stack, int j, int i, int l);
void	check_sort(t_list *lst);
int		ft_lstsize(t_list *lst);
void	sa(t_list **stack_a, int i);
void	sb(t_list **stack_b, int i);
void	ss(t_list **stack_a, t_list **stack_b, int i);
void	pa(t_list **stack_a, t_list **stack_b, int i);
void	pb(t_list **stack_a, t_list **stack_b, int i);
void	ra(t_list **stack_a, int i);
void	rb(t_list **stack_b, int i);
void	rr(t_list **stack_a, t_list **stack_b, int i);
void	rra(t_list **stack_a, int i);
void	rrb(t_list **stack_b, int i);
void	rrr(t_list **stack_a, t_list **stack_b, int i);

void	fill_index(t_list *stack);
void	push_to_stack_a(t_list **stack_a, t_list **stack_b);
void	fake_swap(t_list **stack_a, t_list	**stack_b, int max, int largest);
int		max_number(t_list **stack);
int		min_number(t_list **stack);
void	best_move(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjo_or_cat(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str, int flag);
char	*ft_strdup(const char *src);
void	free_node(t_list	**stack);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

#endif