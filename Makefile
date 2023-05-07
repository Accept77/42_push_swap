# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinsyang <jinsyang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 20:00:00 by jinsyang          #+#    #+#              #
#    Updated: 2023/05/07 19:34:38 by jinsyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_M = push_swap.c push_swap_utils.c push_swap_node.c push_swap_rule.c push_swap_rule2.c push_swap_sort.c push_swap_part.c push_swap_sort_a.c\
		ft_printf_address.c ft_printf_char.c ft_printf.c ft_printf_nbr.c

OBJ_M = $(SRC_M:.c=.o)

OBJ = $(OBJ_M)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean:
	rm -rf $(OBJ_M)

fclean: clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all
