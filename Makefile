# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:57:41 by rimagalh          #+#    #+#              #
#    Updated: 2025/01/09 15:47:04 by rimagalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = src/main.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = lib/mlx
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

gdb: CFLAGS += -g

gdb: re

re: fclean all

.PHONY: all clean fclean gdb re
