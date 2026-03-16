# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdoutor- <jdoutor-@student.42lisboa.com>   #+#  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024-12-02 14:26:41 by jdoutor-          #+#    #+#              #
#    Updated: 2024-12-02 14:26:41 by jdoutor-         ###   ########42lisboa   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBCREATE = ar rc
RM = rm -f
LIBFT_DIR = libft
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lXtst

OBJS = $(SRCS:.c=.o)
SRCS =	main.c\
		initialization.c\
		validations/validate_args.c\
		validations/validate_file.c\
		validations/validate_map.c\
		validations/validate_file_utils.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		fill_elements/fill_north.c\
		fill_elements/fill_south.c\
		fill_elements/fill_west.c\
		fill_elements/fill_east.c\
		fill_elements/fill_floor.c\
		fill_elements/fill_ceilling.c\
		fill_map/fill_map.c\
		game/start_game.c\
		game/render.c\
		game/render_utils.c\
		game/moving.c\
		game/rotating.c\
		game/direction_start.c\

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		cp libft/libft.a .
	
	$(CC) $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -lm -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJ) libft.a
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) libft.a
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
