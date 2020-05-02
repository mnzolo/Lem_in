# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmuzeren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 11:45:42 by tmuzeren          #+#    #+#              #
#    Updated: 2020/01/31 11:45:52 by tmuzeren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB=./libft/libft.a

NAME=lem-in

SRC=move.c\
   	farm.c\
   	protection.c\
   	tools.c\
   	g_route.c\
  	lists.c\
   	links_init.c\
	ft_atol.c\

all:$(NAME)

$(NAME):$(LIB)
	@gcc -g -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)

$(LIB):
	@make -C ./libft

clean:
	@make clean -C ./libft

fclean:
	@make fclean -C ./libft
	@rm $(NAME)
re:fclean all
