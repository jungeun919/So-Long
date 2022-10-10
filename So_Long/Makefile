# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 15:45:01 by jungchoi          #+#    #+#              #
#    Updated: 2022/10/07 14:36:06 by jungchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs
OBJS_DIR = objs

MLX_DIR = mlx
MLX = libmlx.a

LIBFT_DIR = libs/libft
LIBFT = libft.a

SRCS = $(addprefix $(SRCS_DIR)/, \
	so_long.c \
	parse_map.c \
	print_map.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) -lft -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(MLX) :
	make -C $(MLX_DIR) all

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	make fclean
	make all

.PHONY = all clean fclean re
