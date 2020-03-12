# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 15:10:44 by mmahasim          #+#    #+#              #
#    Updated: 2020/03/04 15:10:49 by mmahasim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
SRC = *.c
LIBFT_DIR = libft
LIBS = libft/libft.a
OBJ = $(SRC:.c=.o)
HEADERS = fractol.h
all:
	@$(MAKE) -C $(LIBFT_DIR)
	@gcc -o $(NAME) $(SRC) $(LIBS) -lmlx -framework OpenGL -framework AppKit
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
re: fclean all