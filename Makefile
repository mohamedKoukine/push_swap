# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaoukin <mkaoukin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 16:50:44 by mkaoukin          #+#    #+#              #
#    Updated: 2024/02/16 13:14:51 by mkaoukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

CC = CC

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c\
		ft_split.c\
		parsing.c\
		push_swap.c\
		moves1.c\
		moves2.c\
		my_functions.c\
		my2_functions.c\
		my3_functions.c\
		ft_lstadd_back.c\
		ft_lstadd_front.c\
		ft_lstlast.c \
		ft_lstsize.c\
		ft_lstnew.c

SRCB = 	checker.c\
			get_next_line.c\
			ft_lstsize.c\
			parsing.c\
			ft_atoi.c\
			ft_split.c\
			moves1.c\
			moves2.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstlast.c \
			ft_lstnew.c\
			my_functions.c\
			my2_functions.c\
			get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

INCLUDE = push_swap.h

$(NAME) : $(OBJ) $(INCLUDE)
	cc $(OBJ) -o $@

$(NAMEB) : $(OBJB) $(INCLUDE)
	cc $(OBJB) -o $@

%.o : %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

bonus : $(NAMEB)

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all

.PHONY : clean