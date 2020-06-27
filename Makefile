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
HEADER = fractol.h
HEADER_LIB = libft/libft.h
SRC = main.c draw.c ft_hook.c
LIBFT_DIR = libft
MLX_DIR = minilibx_macos
LIB_MLX = minilibx_macos/libmlx.a
LIBS = libft/libft.a
HEADERS = fractol.h
FLAG = -Wall -Wextra -Werror -g
FLAG_MLX = -O3 -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBS) $(LIB_MLX) $(SRC) $(HEADER)
	gcc $(FLAG) -o $(NAME) $(SRC) $(LIBS) $(LIB_MLX) $(FLAG_MLX) -I $(HEADER)

$(LIBS): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(LIB_MLX): $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all