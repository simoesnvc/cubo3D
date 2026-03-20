# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 14:26:41 by jdoutor-          #+#    #+#              #
#    Updated: 2026/03/20 15:39:17 by jdoutor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
MLX_PATH = mlx/

MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lXtst

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
		helpers/texture_helper.c\
		helpers/raycast_helper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

mlx:
	cd $(MLX_PATH) && ./configure && $(MAKE) all

$(NAME): $(OBJS)
	$(MAKE) mlx
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -lm -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re mlx