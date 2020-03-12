# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 18:36:38 by mmahasim          #+#    #+#              #
#    Updated: 2019/09/30 15:42:26 by mmahasim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft.h

FUNCS = $(shell cat ./libft.h | grep -Eo "ft_\w+")

SRC = $(FUNCS:=.c)

OBJ = $(SRC:.c=.o)
	
all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I. $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME)

re: fclean all
